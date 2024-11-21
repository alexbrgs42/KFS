DOCKER_IMAGE	=	kfs

DOCKER_NAME		=	kfs_docker

ISO_FILE		=	kfs.iso

COLOR_GREEN	=	\033[1;32m
COLOR_RED	=	\033[1;31m
COLOR_BLUE	=	\033[3;36m
COLOR_PURP	=	\033[1;35m
COLOR_END	=	\033[0m

all: $(ISO_FILE)

run: $(ISO_FILE)
	kvm kfs.iso

$(ISO_FILE):
	@docker build -t $(DOCKER_IMAGE) .
	@docker run --name $(DOCKER_NAME) -d -i -v .:/kfs $(DOCKER_IMAGE)
	@docker exec -d $(DOCKER_NAME) cp kfs.iso /kfs/kfs.iso
	@docker stop -t 1 $(DOCKER_NAME)
	@echo "$(COLOR_GREEN) || Done !$(COLOR_END)"

clean:
	@rm -rf kfs.iso
	@echo "$(COLOR_RED) || Cleaning files...$(COLOR_END)"

fclean: clean
	@docker system prune -af
	@echo "$(COLOR_RED) || Cleaning docker files...$(COLOR_END)"

re: fclean all

.PHONY: re fclean all clean

-include $(DEPS)