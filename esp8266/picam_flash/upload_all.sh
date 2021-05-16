for f in $(ls *.py);
do echo "Uploading $f...";
../../interpreter/bin/ampy --port /dev/ttyUSB0 put $f;
done
