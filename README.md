# pong

### Просто понг типа по приколу написал

## Построить и побежать):

Чтобы собрать исполняемый файлик `pong`, просто `make` запустить надо без опций, крч.
Из зависимостей здесь только `sfml`, ну и сам `make` с компилятором (по дефолту `g++`, но в `Makefile` поменять не проблема)

Под debian/ubuntu вот так вот устанавливаются зависимости:
	sudo apt update && sudo apt install libsfml-dev make g++
Ну и сборка проекта:
	git clone https://github.com/iv4n-t3a/pong.git
	cd pong
	make
Ну и запустить:
	./pong
Под другии unix-like системы и windows по аналогии, только установка зависимостей будет отличаться

## Демка проектика:

![demo](demo.gif)