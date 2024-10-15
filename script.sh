#!/bin/bash

# Проверка, передано ли имя файла как аргумент
if [ -z "$1" ]; then
  echo "Укажите имя файла как аргумент"
  exit 1
fi

FILENAME=$1

# Проверка, существует ли файл
if [ ! -f "$FILENAME" ]; then
  echo "Файл не существует. Создаем файл $FILENAME."
  # Записываем 10 случайных строк в файл
  for i in {1..10}; do
    echo $RANDOM >> "$FILENAME"
  done
fi

# Подсчет количества строк в файле
NUM_LINES=$(wc -l < "$FILENAME")
echo "Всего строк для отправки: $NUM_LINES"

# Отправка строк на локальный сервер с помощью netcat
while IFS= read -r line; do
  echo "$line" | nc -q 1 localhost 12345
done < "$FILENAME"

echo "Отправлено $NUM_LINES строк."

# Запуск фонового процесса для записи текущего времени в log.txt каждую минуту
(
  while true; do
    echo "$(date)" >> log.txt
    sleep 60ёё
  done
) &

echo "Фоновый процесс запущен для записи времени в log.txt"
