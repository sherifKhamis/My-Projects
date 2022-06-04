import pygame
import numpy


pygame.init()

#display size
surface = pygame.display.set_mode((500,500))
pygame.display.set_caption('TicTacToe')

#background color 
bg_color = (28,170,156)
surface.fill(bg_color)
pygame.display.flip()

line_color = (23,145,135)

#lines 
pygame.draw.line(surface, line_color, (0,166), (500,166), 10)
pygame.draw.line(surface, line_color, (0,332), (500,332), 10)
pygame.draw.line(surface, line_color, (166,0), (166,500), 10)
pygame.draw.line(surface, line_color, (332,0), (332,500), 10)
pygame.display.flip()

board = numpy.zeros ((3,3))

def mark_square(row, col, player):
    board[row][col] = player

def available_square (row, col):
    return board[row][col] == 0


running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False


