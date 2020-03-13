for concurrency in 5
do
    for length in 100
    do
        python run.py -f bench_text.txt -l $length -c $concurrency -s 127.0.0.1:12345
    done
done
