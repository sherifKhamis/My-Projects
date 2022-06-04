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
player = 1
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        if event.type == pygame.MOUSEBUTTONDOWN:
            mouseX = event.pos[1]
            mouseY = event.pos[0]

            clicked_row = int (mouseX // 200)
            clicked_col = int (mouseY // 200)

            if available_square(clicked_row, clicked_col):
                if player==1:
                    mark_square(clicked_row, clicked_col, 1)
                    player = 2
                elif player == 2:
                    mark_square(clicked_row, clicked_col, 2)
                    player = 1
            
                draw_figures()
    pygame.display.update()
    