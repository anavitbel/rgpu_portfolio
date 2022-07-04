"""
    Автор: Моисеенко Павел, подгруппа № 2.

    ИСР 2.2. Задание: разработать программу, позволяющую генерировать
    уникальные идентификаторы: UUID (universally unique identifier).
    Структура UUID — на усмотрение студента.

"""


import uuid

domain = str(input("Введите домен: "))
generated_uuid = uuid.uuid3(uuid.NAMESPACE_DNS, domain)
print(generated_uuid)
