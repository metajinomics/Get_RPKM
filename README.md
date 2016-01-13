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


~~~
g++ Get_RPKM_for_IMG.cpp -o Get_RPKM_for_IMG
./Get_RPKM_for_IMG rnaseq_expression.txt imgout.txt
~~~

~~~
g++ Get_RPKM.cpp -o Get_RPKM
./Get_RPKM counts.txt normal_counts.txt
~~~
