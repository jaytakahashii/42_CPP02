MAKEFILE 		= Makefile

NAME				= UsefulFixed-Point

SRC_DIR			= src/
OBJ_DIR			= .obj/

INCLUDE_DIR	= include/
INCLUDE			= -I $(INCLUDE_DIR)
HEADERS			= Fixed.hpp
HEADER			= $(addprefix $(INCLUDE_DIR), $(HEADERS))

DEPS				= $(HEADER) $(MAKEFILE)

CXX					= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

RM					= rm -rf

SRC_DIR			= src/
SRC_FILES		=	main.cpp \
							Fixed.cpp

SRCS				= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS				= $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

# color ************
Y		= "\033[33m"
R		= "\033[31m"
G		= "\033[32m"
B		= "\033[34m"
X		= "\033[0m"
UP	= "\033[A"
CUT	= "\033[K"
# ******************

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(DEPS)
	@echo $(Y) "$(NAME) src files successfully compiled\n" $(X)
	@echo $(B) "$(NAME) creating" $(X)
	@printf $(UP)$(CUT)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo $(G) "!! $(NAME) created !!\n" $(X)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	@echo $(Y) "Compiling $<" $(X)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@
	@printf $(UP)$(CUT)

clean:
	@$(RM) $(OBJ_DIR)
	@echo $(R) "$(OBJ_DIR) has been removed!!" $(X)

fclean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo $(R) "$(NAME) $(OBJ_DIR) has been removed!!" $(X)

re: fclean all

.PHONY: all clean fclean re
