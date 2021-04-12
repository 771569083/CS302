#! /bin/bash
if [ -f $2 ]
then
rm $2
touch $2
fi
num_file=0
num_dir=-1
abs=$(readlink -f $1)
bfs_dir(){
array=()
index=0
array[${#array[@]}]=$abs
while [ ${#array[@]} -ne $index ]
do
A=${array[$index]}
index=`expr $index + 1`
if [ -d "$A" ]
then
echo "[${A##*/}]" >> $2
num_dir=`expr $num_dir + 1`
tmp_arr=$(ls "$A")
readarray -t tmp_arr <<< "$tmp_arr"
j=${#tmp_arr[@]}
for((i=0;i<$j;i++))
do
	if [ -n "${tmp_arr[$i]##*/}" ]
	then
		array[${#array[@]}]=${A}"/"${tmp_arr[$i]}
		echo ${array[`expr ${#array[@]} - 1`]}
		echo "${A}"/"${tmp_arr[$i]}" >> $2
	fi
done
echo >> $2
elif [ -f "$A" ]
then
num_file=`expr $num_file + 1`
else
	echo 1
fi
done
}
bfs_dir $1 $2
echo "[Directories Count]:${num_dir}" >> $2
echo "[Files Count]:${num_file}" >> $2
