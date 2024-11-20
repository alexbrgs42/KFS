IMAGE_NAME	=	kfs_build
ISO_FILE	=	kfs.iso

all: $(ISO_FILE)

# TODO : Run the docker with a shared volume maybe
$(ISO_FILE): 
	docker build -t $(IMAGE_NAME) .
	docker cp $(IMAGE_NAME):kfs.iso kfs.iso

fclean:
	docker system prune -af