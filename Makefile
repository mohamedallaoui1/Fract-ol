NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
RED = \033[0;31m
RED_DR = \033[2;31m
RESET = \033[0m
BLUE = \033[0;34m


SRC = controls.c fract_ol.c mandelbrot.c julia.c burning_ship.c utils.c utils3.c utils2.c
OBJ = ${SRC:.c=.o}
all: ${NAME}

${NAME}: ${OBJ}
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)
	@clear
	@echo "$(RED)█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████"
	@echo "$(RED)█$(BLUE)░░░░░░░░░░░░░░$(RED)█$(BLUE)░░░░░░░░░░░░░░░░$(RED)███$(BLUE)░░░░░░░░░░░░░░$(RED)█$(BLUE)░░░░░░░░░░░░░░$(RED)█$(BLUE)░░░░░░░░░░░░░░$(RED)████████████████$(BLUE)░░░░░░░░░░░░░░$(RED)█$(BLUE)░░░░░░$(RED)████████$(RED)█"
	@echo "$(RED)█$(BLUE)░░▄▀▄▀▄▀▄▀▄▀░░$(RED)█$(BLUE)░░▄▀▄▀▄▀▄▀▄▀▄▀░░$(RED)███$(BLUE)░░▄▀▄▀▄▀▄▀▄▀░░$(RED)█$(BLUE)░░▄▀▄▀▄▀▄▀▄▀░░$(RED)█$(BLUE)░░▄▀▄▀▄▀▄▀▄▀░░$(RED)████████████████$(BLUE)░░▄▀▄▀▄▀▄▀▄▀░░$(RED)█$(BLUE)░░▄▀░░$(RED)████████$(RED)█"
	@echo "$(RED)█$(BLUE)░░▄▀░░░░░░░░░░$(RED)█$(BLUE)░░▄▀░░░░░░░░▄▀░░$(RED)███$(BLUE)░░▄▀░░░░░░▄▀░░$(RED)█$(BLUE)░░▄▀░░░░░░░░░░$(RED)█$(BLUE)░░░░░░▄▀░░░░░░$(RED)████████████████$(BLUE)░░▄▀░░░░░░▄▀░░$(RED)█$(BLUE)░░▄▀░░$(RED)████████$(RED)█"
	@echo "$(RED)█$(BLUE)░░▄▀░░$(RED)█████████$(BLUE)░░▄▀░░████░░▄▀░░$(RED)███$(BLUE)░░▄▀░░██░░▄▀░░$(RED)█$(BLUE)░░▄▀░░$(RED)█████████████$(BLUE)░░▄▀░░$(RED)████████████████████$(BLUE)░░▄▀░░$(RED)██$(BLUE)░░▄▀░░$(RED)█$(BLUE)░░▄▀░░$(RED)████████$(RED)█"
	@echo "$(RED)█$(BLUE)░░▄▀░░░░░░░░░░$(RED)█$(BLUE)░░▄▀░░░░░░░░▄▀░░$(RED)███$(BLUE)░░▄▀░░░░░░▄▀░░$(RED)█$(BLUE)░░▄▀░░$(RED)█████████████$(BLUE)░░▄▀░░$(RED)█████$(BLUE)░░░░░░░░░░░░░░$(RED)█$(BLUE)░░▄▀░░$(RED)██$(BLUE)░░▄▀░░$(RED)█$(BLUE)░░▄▀░░$(RED)████████$(RED)█"
	@echo "$(RED)█$(BLUE)░░▄▀▄▀▄▀▄▀▄▀░░$(RED)█$(BLUE)░░▄▀▄▀▄▀▄▀▄▀▄▀░░$(RED)███$(BLUE)░░▄▀▄▀▄▀▄▀▄▀░░$(RED)█$(BLUE)░░▄▀░░$(RED)█████████████$(BLUE)░░▄▀░░$(RED)█████$(BLUE)░░▄▀▄▀▄▀▄▀▄▀░░$(RED)█$(BLUE)░░▄▀░░$(RED)██$(BLUE)░░▄▀░░$(RED)█$(BLUE)░░▄▀░░$(RED)████████$(RED)█"
	@echo "$(RED)█$(BLUE)░░▄▀░░░░░░░░░░$(RED)█$(BLUE)░░▄▀░░░░░░▄▀░░░░$(RED)███$(BLUE)░░▄▀░░░░░░▄▀░░$(RED)█$(BLUE)░░▄▀░░$(RED)█████████████$(BLUE)░░▄▀░░$(RED)█████$(BLUE)░░░░░░░░░░░░░░$(RED)█$(BLUE)░░▄▀░░$(RED)██$(BLUE)░░▄▀░░$(RED)█$(BLUE)░░▄▀░░$(RED)████████$(RED)█"
	@echo "$(RED)█$(BLUE)░░▄▀░░$(RED)█████████$(BLUE)░░▄▀░░$(RED)██$(BLUE)░░▄▀░░$(RED)█████$(BLUE)░░▄▀░░$(RED)██$(BLUE)░░▄▀░░$(RED)█$(BLUE)░░▄▀░░$(RED)█████████████$(BLUE)░░▄▀░░$(RED)████████████████████$(BLUE)░░▄▀░░$(RED)██$(BLUE)░░▄▀░░$(RED)█$(BLUE)░░▄▀░░$(RED)████████$(RED)█"
	@echo "$(RED)█$(BLUE)░░▄▀░░$(RED)█████████$(BLUE)░░▄▀░░$(RED)██$(BLUE)░░▄▀░░░░░░$(RED)█$(BLUE)░░▄▀░░$(RED)██$(BLUE)░░▄▀░░$(RED)█$(BLUE)░░▄▀░░░░░░░░░░$(RED)█████$(BLUE)░░▄▀░░$(RED)████████████████████$(BLUE)░░▄▀░░░░░░▄▀░░$(RED)█$(BLUE)░░▄▀░░░░░░░░░░$(RED)█"
	@echo "$(RED)█$(BLUE)░░▄▀░░$(RED)█████████$(BLUE)░░▄▀░░$(RED)██$(BLUE)░░▄▀▄▀▄▀░░$(RED)█$(BLUE)░░▄▀░░$(RED)██$(BLUE)░░▄▀░░$(RED)█$(BLUE)░░▄▀▄▀▄▀▄▀▄▀░░$(RED)█████$(BLUE)░░▄▀░░$(RED)████████████████████$(BLUE)░░▄▀▄▀▄▀▄▀▄▀░░$(RED)█$(BLUE)░░▄▀▄▀▄▀▄▀▄▀░░$(RED)█"
	@echo "$(RED)█$(BLUE)░░░░░░$(RED)█████████$(BLUE)░░░░░░$(RED)██$(BLUE)░░░░░░░░░░$(RED)█$(BLUE)░░░░░░$(RED)██$(BLUE)░░░░░░$(RED)█$(BLUE)░░░░░░░░░░░░░░$(RED)█████$(BLUE)░░░░░░$(RED)████████████████████$(BLUE)░░░░░░░░░░░░░░$(RED)█$(BLUE)░░░░░░░░░░░░░░$(RED)█"
	@echo "$(RED)████████████████████████████████████████████████████████████████████████████████████████████████████████████████\033[41mBy: @mallaoui$(RESET)"
	@echo "\033[1;33mHow to compile : \033[1;31m./fractol\033[0m \033[1;32m[Name of fractal] \033[1;35m[Real part] [Imaginairy part]\033[0m"
	@echo "	\033[1;32m[Name of fractal] : mandelbrot julia burningship\033[0m"
	@echo "	\033[1;35m[\033[1;32mJulia \033[1;35mOptions] : [Real part] [Imaginairy part] \033[1;37m⚠️ ONLY FOR JULIA ⚠️\033[0m"
	@echo "\033[1;33mUsage :\033[0m"
	@echo "	\033[1;37mZoom \033[1;31mIN \033[1;37mor \033[1;31mOUT \033[1;37musing the \033[1;31mscroll wheel\033[0m"
	@echo "	\033[1;37mMove using the \033[1;31mUP \033[1;37mor \033[1;31mDOWN\033[0m"
	@echo "	\033[1;37mor \033[1;31mLEFT \033[1;37mor \033[1;31mRIGHT \033[1;37marrow kies in the keyboard\033[0m"
	@echo "	\033[1;37mChange color with the Buttons : \033[1;31mR \033[1;32mG \033[1;36mB\033[0m"
	@echo "	\033[1;37mTo get back to the defualt mode press the \033[1;31mmiddle mouse button\033[0m"

clean:
	@rm -f $(OBJ)
	@clear

fclean: clean
	@rm -f $(NAME)
	@clear


re: fclean all
