"""
Разработать фрагмент программы, позволяющий получать данные о текущих курсах валют с сайта Центробанка РФ с использованием сервиса, который они предоставляют. Применить шаблон проектирования «Одиночка» для предотвращения отправки избыточных запросов к серверу ЦБ РФ (запретить вызов функции get_currencies более 1 раза в секунду). Оформить решение в виде корректно работающего приложения, реализовать тестирование и опубликовать его в портфолио.

Страница документации: https://cbr.ru/development/
"""

# http://www.cbr.ru/scripts/XML_daily.asp
import requests
from time import sleep
from xml.etree import ElementTree as ET


def singleton(cls):
    instances = {}

    def getinstance():
        if cls not in instances:
            instances[cls] = cls()
        return instances[cls]

    return getinstance


@singleton
class CurrenciesList():
    def __init__(self):
        self.inited = False

    def get_currencies(self, currencies_ids_lst=None):

        if self.inited:
            sleep(1)

        self.inited = True

        if currencies_ids_lst is None:
            currencies_ids_lst = [
                'R01239', 'R01235', 'R01035', 'R01815', 'R01585F', 'R01589',
                'R01625', 'R01670', 'R01700J', 'R01710A'
            ]

        cur_res_str = requests.get('http://www.cbr.ru/scripts/XML_daily.asp')

        result = {}

        # XML Tree
        root = ET.fromstring(cur_res_str.content)

        valutes = root.findall("Valute")

        for _v in valutes:
            valute_id = _v.get('ID')

            if str(valute_id) in currencies_ids_lst:
                valute_cur_val = _v.find('Value').text
                valute_cur_name = _v.find('Name').text

                result[valute_id] = (valute_cur_val, valute_cur_name)

        return result


my_cur_list = CurrenciesList()
print(id(my_cur_list))

res = my_cur_list.get_currencies(["R01090B", "R01720", "R01565"])
print(res)
