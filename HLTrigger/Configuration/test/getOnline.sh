#! /bin/bash

HLT='/users/fwyzard/test/20100222.162100/HLT/V1'

rm -f OnData_HLT_TEST.py
rm -f OnLine_HLT_TEST.py

./getHLT.py --process TEST --full --offline --mc   $HLT TEST
mv OnLine_HLT_TEST.py offline_mc.py
./getHLT.py --process TEST --full --offline --data $HLT TEST
mv OnData_HLT_TEST.py offline_data.py
./getHLT.py --process TEST --full --online  --data $HLT TEST
mv OnData_HLT_TEST.py online_data.py
