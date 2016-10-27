from __future__ import print_function
from IPython.display import clear_output
from time import sleep
from random import choice
import pygame
import string

white=(255,255,255)
black=(0,0,0)
red=(255,0,0)
blue=(0,0,255)

SIZE_X, SIZE_Y = 10, 10
NUM_PRED, NUM_VIC, NUM_OBST = 15, 40, 10
def get_key():
  while 1:
    event = pygame.event.poll()
    if event.type == pygame.KEYDOWN:
      return event.key
    else:
      pass

def display_box(screen, message):
  "Print a message in a box in the middle of the screen"
  fontobject = pygame.font.Font(None,18)
  pygame.draw.rect(screen, (0,0,0),
                   ((screen.get_width() / 2) - 100,
                    (screen.get_height() / 2) - 10,
                    200,20), 0)
  pygame.draw.rect(screen, (255,255,255),
                   ((screen.get_width() / 2) - 102,
                    (screen.get_height() / 2) - 12,
                    204,24), 1)
  if len(message) != 0:
    screen.blit(fontobject.render(message, 1, (255,255,255)),
                ((screen.get_width() / 2) - 100, (screen.get_height() / 2) - 10))
  pygame.display.flip()


def ask(screen, question):
  "ask(screen, question) -> answer"
  pygame.font.init()
  current_string = []
  display_box(screen, question + ": " + string.join(current_string,""))
  while 1:
    inkey = get_key()
    if inkey == pygame.K_BACKSPACE:
      current_string = current_string[0:-1]
    elif inkey == pygame.K_RETURN:
      break
    elif inkey == pygame.K_MINUS:
      current_string.append("_")
    elif inkey <= 127:
      current_string.append(chr(inkey))
    display_box(screen, question + ": " + string.join(current_string,""))
  return string.join(current_string,"")
'''
pygame.init()
screen = pygame.display.set_mode((320,240))
str1=ask(screen, "ENTER X SIZE")
str2=ask(screen, "ENTER Y SIZE")
str3=ask(screen,"Enter number of obstacles")
pygame.quit()
SIZE_X=int(str1)
SIZE_Y=int(str2)
NUM_OBST=int(str3)
'''

def initialize_field():
    '''
    Returns a list of SIZE_X lists (each of length SIZE_y)
    with NUM_PRED 'X's (for predators), NUM_VIC 'O's (for victims)
    and NUM_OBST '#'s (for obstacles) in random places. Each remaining element
    contains a '*'.
    '''
    field = [['*'] * SIZE_X for y in range(SIZE_Y)]
    cell_idx = [(x, y) for x in xrange(SIZE_X)
                for y in xrange(SIZE_Y)]

    # add predators
    num_pred = NUM_PRED
    while (num_pred):
        col, row = choice(cell_idx)
        if field[row][col] == '*':
            field[row][col] = 'X'
            num_pred -= 1

    # add victims
    num_vic = NUM_VIC
    while (num_vic):
        col, row = choice(cell_idx)
        if field[row][col] == '*':
            field[row][col] = 'O'
            num_vic -= 1

    # add obstacles
    num_obst = NUM_OBST
    while (num_obst):
        col, row = choice(cell_idx)
        if field[row][col] == '*':
            field[row][col] = '#'
            num_obst -= 1

    return field

def print_field(field, clear_all=True):
    '''
    Prints the field (a list of lists). If the field is big, it sucks :)

    :param field - a list of lists
    :param clear_all - whether to clear previous output.
    '''
    if clear_all:
        clear_output()
    print('/' * (2 * SIZE_X + 5))
    for col in range(len(field)):
        print('// ', end='')
        for row in range(len(field[0])):
            print(field[col][row], end=' ')
        print('//')
    print('/' * (2 * SIZE_X + 5))

def process_one_cell(field, (col, row)):
    '''
    If a cell (col, row) is occupied with 'X' or 'O'
    it modifies the field  and returns a new one.

    :param field - a list of lists
    :param (col, row) - a tuple with 2 integer coordinates.
                        col should be in [0, SIZE_X - 1],
                        row should be in [0, SIZE_Y - 1]
    :return field, (new_col, new_row) - filed is a modified list of lists,
                   (new_col, new_row) - are the coordinates of a new cell
                   or the old obe if there was no movement
    '''
    if field[col][row] in ['X', 'O']:
        cur_animal = field[col][row]
        possible_moves = []
        for (new_col, new_row) in [(col, min(row + 1, SIZE_X - 1)),
                                   (col, max(row - 1, 0)),
                                   (max(col - 1, 0), row),
                                   (min(col + 1, SIZE_Y - 1), row)]:
            if field[new_col][new_row] != "#":
                possible_moves.append((new_col, new_row))
        if possible_moves:
            new_col, new_row = choice(possible_moves)
            if field[col][row]=='O' and field[new_col][new_row]=='X' :
                field[col][row]='*'
            elif field[col][row]=='O' and field[new_col][new_row]=='*':
                field[new_col][new_row] = cur_animal
                field[col][row] = '*'
            elif field[col][row]=='X' and (field[new_col][new_row] in ['*','O']):
                field[new_col][new_row] = cur_animal
                field[col][row] = '*'

            return field, (new_col, new_row)
    return field, (col, row)


def process_field(field, verbose=False):
    '''
    Applies process_one_cell to each cell with repsect to the fact
    that a cell should not be processed if it has already been a destination
    of a previous move.

    :param field - a list of lists
    :param verbose - whether to print the moves

    :return field - a modified list of lists
    '''
    processed_cells = []
    for col in range(SIZE_Y):
        for row in range(SIZE_X):
            if (col, row) not in processed_cells:
                field, (new_col, new_row) = process_one_cell(field, (col, row))
                if (new_col, new_row) != (col, row):
                    processed_cells.append((new_col, new_row))
    return field



f = initialize_field()
print_field(f)
pygame.init()

temp1=max(SIZE_X,SIZE_Y)
objSize=(800-2*temp1)/temp1

projDisplay=pygame.display.set_mode((800,800))
pygame.display.set_caption('Jungle')
projExit=False
while not projExit:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                 projExit = True
        projDisplay.fill(white)
        for row in range(SIZE_Y):
            for col in range(SIZE_X):
                if f[row][col]=='X':
                    pygame.draw.rect(projDisplay, red, [col * (objSize + 2), row * (objSize + 2), objSize, objSize])
                if f[row][col]=='O':
                    pygame.draw.rect(projDisplay, blue, [col * (objSize + 2), row * (objSize + 2), objSize, objSize])
                if f[row][col]=='#':
                    pygame.draw.rect(projDisplay, black, [col * (objSize + 2), row * (objSize + 2), objSize, objSize])
        pygame.display.update()
        f = process_field(f, verbose=True)
        sleep(0.5)
pygame.quit()



