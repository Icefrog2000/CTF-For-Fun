Can you figure out why s/<script>//gi is insufficient for sanitizing? This can be bypassed with <scr<script>ipt>.

Remove <script> (case insensitive) from the input until the input contains no <script>.

Note that flag format is SECCON{[\x20-\x7e]+}, which means that the flag may contains < or > as the following examples.

Sample Input 1:

S3CC0N{dum<scr<script>ipt>my}
Sample Output 1:

S3CC0N{dummy}
Sample Input 2 (small.txt):

S3CC0N{dumm<scrIpT>y_flag>_<_pt>>PT><<SCr<S<<SC<SCRIpT><scRiPT>Ript>sCr<Scri<...
Sample Output 2:

S3CC0N{dummy_flag>_<_pt>>PT><sCRIp<scr<scr<scr!pt>ipt>ipt>}
flag.tar.gz aa8c833f5313809dc2cd1e8fc14e66d1e6d1e101