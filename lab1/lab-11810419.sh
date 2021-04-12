#! /bin/bash
num_file=0
num_dir=-1
bfs_dir(){
	array=()
	out=$2
	array[${#array[@]}]=$1
	while [ ${#array[@]} -gt 0 ]
	do
		A=${array[0]}
		array=(${array[@]:1})
		if [ -d $A ]
		then
		       	echo "\["$A"\]">>$out
			num_dir= $(($num_dir+1))
			for file in `ls $A`
			do
				array[${#array[@]}]=$A"/"$file
				echo $A"/"$file>>$out
			done
			echo "\n">>$out
		else
			num_file=$(($num_file+1))
		fi
	done
}
bfs_dir $1 $2
echo "[Directories Count]:${num_dir}">>$2
echo "[Files Count]:${num_file}">>$2
