build:
	docker-compose build

up:
	docker-compose up -d

down:
	docker-compose down

stop:
	docker-compose stop

clean:
	docker-compose down -v

logs:
	docker-compose logs -f

rebuild: build up

.PHONY: build up down stop clean logs rebuild
