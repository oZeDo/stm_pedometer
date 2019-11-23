from pymongo import MongoClient
from serial import Serial
from pymongo import errors
ser = Serial("COM7", 9600)
db = MongoClient('165.22.199.70', username='mongo-root', password='Craft777@')
i = 0
while True:
    try:
        cc = str(ser.readline())[2:][:-5]
        dd = str(ser.readline())[2:][:-5]
        post_id = db.stm.data.insert_one({"_id": i, "acc": cc, "gyr": dd})
        print(i, cc, dd, post_id.inserted_id)
        i += 1
    except errors.DuplicateKeyError:
        i += 1
        continue
