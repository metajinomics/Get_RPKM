echo Contig > Contig.txt
echo Length > Length.txt
echo Desc. > Desc.txt
ls *.idxstats.txt | head -1 > fileNameTemp
for line in $(cat fileNameTemp);
do
cat $line | cut -f1 -s >> Contig.txt;
cat $line | cut -f2 -s >> Length.txt;
cat $line | cut -f1 -s >> Desc.txt;
done

for x in *.idxstats.txt; do echo ${x%%_*} > $x.col.txt ; cat $x | cut -f3 -s >> $x.col.txt; done

paste Contig.txt Length.txt Desc.txt *.col.txt > counts.txt

rm Contig.txt
rm Length.txt
rm Desc.txt
rm *.col.txt