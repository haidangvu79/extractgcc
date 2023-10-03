search_dir='./converted/*.c'

for entry in $search_dir
do
    echo "$entry"
    /opt/kalray/accesscore/bin/kvx-cos-gcc "$entry" -o "$entry".o
    /opt/kalray/accesscore/bin/kvx-cluster -- "$entry".o > "$entry".txt
done

cp converted/*.txt traces/
