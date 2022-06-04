import pygame
import numpy


pygame.init()

CIRCLE_COLOR = (239, 231, 200)
CROSS_COLOR = (66, 66, 66)
SQUARE_SIZE = 200
CIRCLE_RADIUS = 60
CIRCLE_WIDTH = 15
CROSS_WIDTH = 25
SPACE = 55

#display size
surface = pygame.display.set_mode((600,600))
pygame.display.set_caption('TicTacToe')

#background color 
bg_color = (28,170,156)
surface.fill(bg_color)
pygame.display.flip()

line_color = (23,145,135)

#lines 
pygame.draw.line(surface, line_color, (0,200), (600,200), 10)
pygame.draw.line(surface, line_color, (0,400), (600,400), 10)
pygame.draw.line(surface, line_color, (200,0), (200,600), 10)
pygame.draw.line(surface, line_color, (400,0), (400,600), 10)
pygame.display.flip()

board = numpy.zeros ((3,3))

def mark_square(row, col, player):
    board[row][col] = player

def available_square (row, col):
    return board[row][col] == 0

def draw_figures():
	for row in range(3):
		for col in range(3):
			if board[row][col] == 1:
				pygame.draw.circle( surface, CIRCLE_COLOR, (int( col * SQUARE_SIZE + SQUARE_SIZE//2 ), int( row * SQUARE_SIZE + SQUARE_SIZE//2 )), CIRCLE_RADIUS, CIRCLE_WIDTH )
			elif board[row][col] == 2:
				pygame.draw.line( surface, CROSS_COLOR, (col * SQUARE_SIZE + SPACE, row * SQUARE_SIZE + SQUARE_SIZE - SPACE), (col * SQUARE_SIZE + SQUARE_SIZE - SPACE, row * SQUARE_SIZE + SPACE), CROSS_WIDTH )	
				pygame.draw.line( surface, CROSS_COLOR, (col * SQUARE_SIZE + SPACE, row * SQUARE_SIZE + SPACE), (col * SQUARE_SIZE + SQUARE_SIZE - SPACE, row * SQUARE_SIZE + SQUARE_SIZE - SPACE), CROSS_WIDTH )

def draw_vertical_winning_line(col, player):
	posX = col * SQUARE_SIZE + SQUARE_SIZE//2

	if player == 1:
		color = CIRCLE_COLOR
	elif player == 2:
		color = CROSS_COLOR

	pygame.draw.line( surface, color, (posX, 15), (posX, 600 - 15), 10)

def draw_horizontal_winning_line(row, player):
	posY = row * SQUARE_SIZE + SQUARE_SIZE//2

	if player == 1:
		color = CIRCLE_COLOR
	elif player == 2:
		color = CROSS_COLOR

	pygame.draw.line( surface, color, (15, posY), (600 - 15, posY), 10 )

def draw_asc_diagonal(player):
	if player == 1:
		color = CIRCLE_COLOR
	elif player == 2:
		color = CROSS_COLOR

	pygame.draw.line( surface, color, (15, 600 - 15), (600 - 15, 15), 10)

def draw_desc_diagonal(player):
	if player == 1:
		color = CIRCLE_COLOR
	elif player == 2:
		color = CROSS_COLOR

	pygame.draw.line( surface, color, (15, 15), (600 - 15, 600 - 15), 10)

def check_win(player):
	# vertical win check
	for col in range(3):
		if board[0][col] == player and board[1][col] == player and board[2][col] == player:
			draw_vertical_winning_line(col, player)
			return True

	# horizontal win check
	for row in range(3):
		if board[row][0] == player and board[row][1] == player and board[row][2] == player:
			draw_horizontal_winning_line(row, player)
			return True

	# asc diagonal win check
	if board[2][0] == player and board[1][1] == player and board[0][2] == player:
		draw_asc_diagonal(player)
		return True

	# desc diagonal win chek
	if board[0][0] == player and board[1][1] == player and board[2][2] == player:
		draw_desc_diagonal(player)
		return True

	return False

gameOver = False
player = 1
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        if event.type == pygame.MOUSEBUTTONDOWN and not gameOver:
            mouseX = event.pos[1]
            mouseY = event.pos[0]

            clicked_row = int (mouseX // 200)
            clicked_col = int (mouseY // 200)

            if available_square(clicked_row, clicked_col):
                if player==1:
                    mark_square(clicked_row, clicked_col, 1)
                    if check_win(player):
                        gameOver = True
                    player = 2
                elif player == 2:
                    mark_square(clicked_row, clicked_col, 2)
                    if check_win(player):
                        gameOver = True
                    player = 1
            
                draw_figures()
    pygame.display.update()
    