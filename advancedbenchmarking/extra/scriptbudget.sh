
for inter in simd galloping scalar; do
echo "%%%% Trying out uncompressed first" $inter
./budgetedtest /home/data/clueweb/Uncompressed/flat.bin /home/data/AOL/user-ct-test-collection-01.id -i $inter -q -b 12 -l 5000 
for scheme in bp copy ibp ironpeter kurzbp simdbp2 simdbp4 simdbpm simdbpr simdfastpfor2 simdfastpfor4 simdfastpform simdfastpforr simdibp2 simdibp4 simdibpm simdibpr simdifastpfor2 simdifastpfor4 simdifastpform simdifastpforr simdvarintgb4 simdvarintgbr simdvarintgbr2 simdvarintgbrm varintgbr varintr; do
echo "######## testing" $inter $scheme
./budgetedtest /home/data/clueweb/Uncompressed/flat.bin /home/data/AOL/user-ct-test-collection-01.id -i $inter -s $scheme -q -b 12 -l 5000
for p in 8 16 32; do
echo "##### number of partitions = " $p
./budgetedtest /home/data/clueweb/Uncompressed/flat.bin /home/data/AOL/user-ct-test-collection-01.id -i $inter -s $scheme -q -b 12 -l 5000 -p $p
echo
done
done
done
