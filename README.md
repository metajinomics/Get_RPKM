# Get_RPKM

This script automate downstream work after mapping

Let's assume you have *.idxstats.txt files

This command will give you counts.txt
```
bash idxstatsWorkFlow.sh
```

To normalize by RPKM,
```
g++ Get_RPKM.cpp -o Get_RPKM
./Get_RPKM RPKMexample.txt test_output.txt
```

For the downstream from IMG
~~~
g++ Get_RPKM_for_IMG.cpp -o Get_RPKM_for_IMG
./Get_RPKM_for_IMG rnaseq_expression.txt imgout.txt
~~~
For the downstram from standard assembly count table
~~~
g++ Get_RPKM_for_assembly.cpp -o Get_RPKM_for_assembly 
./Get_RPKM_for_assembly counts.txt normal_counts.txt
~~~
