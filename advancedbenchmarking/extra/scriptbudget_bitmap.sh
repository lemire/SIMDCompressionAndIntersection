make entropy budgetedtest
./entropy /home/data/clueweb/Uncompressed/flat.bin /home/data/AOL/user-ct-test-collection-01.id -b 12 -l 1000
for inter in simd galloping; do
for scheme in kurzbp  simdfastpforr fastpfor varintr ; do
echo "######## testing" $inter $scheme
for B in  8 32 ; do
echo "# B = " $B
./budgetedtest /home/data/clueweb/Uncompressed/flat.bin /home/data/AOL/user-ct-test-collection-01.id -i $inter -s $scheme -q -b 12 -l 1000 -B $B
echo
done
done
done
./email.sh
