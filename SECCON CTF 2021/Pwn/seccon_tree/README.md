Let's make your own tree! nc seccon-tree.quals.seccon.jp 30001

Here is an example.

from seccon_tree import Tree

cat = Tree("cat")
lion = Tree("lion")
tiger = Tree("tiger")

cat.add_child_left(lion)
cat.add_child_right(tiger)

assert(cat.find("lion") is not None)
assert(lion.find("tiger") is None)
seccon_tree.tar.gz 64a808f496b9a0173fe731cbbed76e63d1fbf1b1