#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/miscdevice.h>

static struct kmem_cache *module_cache;

static DEFINE_MUTEX(module_mutex);

#define	KM_NOSLEEP	0x0001

MODULE_LICENSE("GPL");
MODULE_AUTHOR("h0ps");

#define DEVICE_NAME "bank"
#define MAX_SZ 108

typedef struct {
    int balance;
    char name[MAX_SZ];
} obj_t;

typedef struct {
    unsigned idx;
    unsigned idx2;
    unsigned amount;
    int* balance;
    char* name;
    size_t len;
} req_t;

#define MAX_OBJS 0x10
obj_t *objs[MAX_OBJS];

#define BANK_CREATE    0x1337
#define BANK_VIEW      0x1338
#define BANK_EDIT      0x1339
#define BANK_DELETE    0x133a
#define BANK_TRANSFER  0x133b
#define BANK_LOAN      0x133c

static int _free_slot(void)
{
    int i;
    for (i = 0; i < MAX_OBJS; i++) {
        if (objs[i] == NULL) {
            return i;
        }
    }

    return -1;
}

static int _create(req_t* req)
{
    int idx = _free_slot();
    if (idx < 0) {
        return -1;
    }

    obj_t *obj = kmem_cache_alloc(module_cache, KM_NOSLEEP);
    if (obj == NULL) {
        return -1;
    }

    memset(obj, 0x00, sizeof(obj_t));
  
    objs[idx] = obj;

    return 0;
}

static int _edit(req_t* req)
{
    if (req->idx >= MAX_OBJS) {
        return -1;
    }

    if (req->len > MAX_SZ) {
        return -1;
    }

    obj_t *obj = objs[req->idx];

    if (obj == NULL) {
        return -1;
    }

    copy_from_user(obj->name, req->name, req->len);

    return 0;
}

static int _view(req_t* req)
{
    if (req->idx >= MAX_OBJS) {
        return -1;
    }

    obj_t *obj = objs[req->idx];

    if (obj == NULL) {
        return -1;
    }

    copy_to_user(req->name, obj->name, sizeof(obj->name));
    copy_to_user(req->balance, &obj->balance, sizeof(obj->balance));

    return 0;
}

static int _delete(req_t *req)
{
    if (req->idx >= MAX_OBJS) {
        return -1;
    }

    obj_t *obj = objs[req->idx];

    if (obj == NULL) {
        return -1;
    }

    kmem_cache_free(module_cache, (void *)obj);

    objs[req->idx] = NULL;

    return 0;
}

static int _transfer(req_t *req)
{
    if (req->idx >= MAX_OBJS || req->idx2 >= MAX_OBJS) {
        return -1;
    }

    obj_t *from = objs[req->idx];
    obj_t *to = objs[req->idx2];

    if (from == NULL || to == NULL) {
        return -1;
    }

    if (req->amount > from->balance) {
        return -1;
    }

    from->balance -= req->amount;
    to->balance += req->amount;

    return 0;
}

static int _loan(req_t *req)
{
    if (req->idx >= MAX_OBJS) {
        return -1;
    }

    obj_t *obj = objs[req->idx];

    if (obj == NULL) {
        return -1;
    }

    if (req->amount > 0x1337) {
        return -1;
    }

    obj->balance += req->amount;

    return 0; 
}

long module_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    mutex_lock(&module_mutex);
    int ret = 0;

    req_t req = {0};

    copy_from_user((void *)&req, (void *)arg, sizeof(req_t));

    switch (cmd) {
        case BANK_CREATE:
            ret =  _create(&req);
            break;
        case BANK_EDIT:
            ret = _edit(&req);
            break;
        case BANK_VIEW:
            ret = _view(&req);
            break;
        case BANK_DELETE:
            ret = _delete(&req);
            break;
        case BANK_TRANSFER:
            ret = _transfer(&req);
            break;
        case BANK_LOAN:
            ret = _loan(&req);
            break;
        default:
              ret = -1;
    }

    mutex_unlock(&module_mutex);
    return ret;
}

int module_open(struct inode *inode, struct file *file)
{
    pr_info("bank module open \n");
    return 0;
}

int module_release(struct inode *inode, struct file *file)
{
    int i;
    for (i = 0; i < MAX_OBJS; i++) {
        if (objs[i] != NULL) {
            kmem_cache_free(module_cache, (void *)objs[i]);
        }
    }
    return 0;
}

static const struct file_operations module_ops = {
    .owner = THIS_MODULE,
    .open = module_open,
    .unlocked_ioctl = module_ioctl,
    .release = module_release
};

static struct miscdevice module_device = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = DEVICE_NAME,
    .fops = &module_ops
};

static int __init my_module_init(void)
{
    module_cache = kmem_cache_create("MY_CACHE",
                                   sizeof (obj_t),
                                   0,
                                   0,
                                   NULL);

    return misc_register(&module_device);
}

static void __exit my_module_exit(void)
{
    kmem_cache_destroy(module_cache);
    misc_deregister(&module_device);
}

module_init(my_module_init);
module_exit(my_module_exit);


