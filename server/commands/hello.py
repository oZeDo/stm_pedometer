import command_system
from pymongo import MongoClient
db = MongoClient('', username='', password='')


def hello():
    message = '''
    Количество записей в БД:{0}
    Количество шагов:{1}
    '''
    s=[]
    counter = 0
    cursor = db.stm.data.find({})
    for i in cursor:
        s.append([i['_id'], i['acc'], i['gyr']])
        if float(i["gyr"]) > 37000:
            counter += 1
    return message.format(len(s), counter), ''


hello_command = command_system.Command()

hello_command.keys = ['статистика', 'statistics', 'stat', 'стат', 'выведи статистику', 'вывод']
hello_command.description = 'Выводит статистику шагомера'
hello_command.process = hello
