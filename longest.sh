# Exam 2020/06/16 - Exercise 4
 
longest_word=""
length_longest=0
cnt=0
 
# Scan the file word by word
for word in $(cat file.txt)
do
    # Detect the length of $word
    length=$(echo $word|wc -c)
    #length=${#word} # Other possibility
 
    if [ $length -gt $length_longest ]
    then
        length_longest=$length
        longest_word=$word
    fi
    let "cnt= cnt + 1"
    echo $cnt $word >> $1 # append

done 
echo $0 # filename (./longest.sh)
echo $longest_word > $1 # override(will dissapear all the cnt word)