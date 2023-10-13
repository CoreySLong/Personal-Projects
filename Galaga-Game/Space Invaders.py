import pygame as pg
from pygame.locals import *


pg.init()

WIDTH = 1200
HEIGHT = 720

bulletGroup = pg.sprite.Group()
superBulletGroup = pg.sprite.Group()

class SuperBullet(pg.sprite.Sprite):
  def __init__(self):
    super(SuperBullet, self).__init__()
    self.sprite = pg.Surface((6,12))
    self.sprite.fill((255,255,0))
    self.rect = self.sprite.get_rect()
    self.rect.y = 700
    self.rect.x = 600

  def update(self):
    self.rect.move_ip(0,-1)     # y axis corresponds to speed

class Bullet(pg.sprite.Sprite):
  def __init__(self):
    super(Bullet, self).__init__()
    self.sprite = pg.Surface((3,6))
    self.sprite.fill((255,255,255))
    self.rect = self.sprite.get_rect()
    self.rect.y = 700
    self.rect.x = 600

  def update(self):
    self.rect.move_ip(0,-1)     # y axis corresponds to speed

class Enemy(pg.sprite.Sprite):
  def __init__(self):      # constructor
    super(Enemy, self).__init__()     # super calls the parent class method (this case constructor)
    self.sprite = pg.image.load("Space_Invaders_Enemy.png")
    self.width = self.sprite.get_width() / 8
    self.height = self.sprite.get_height() / 8
    self.sprite = pg.transform.scale(self.sprite, ((self.width, self.height))) # resizes the image
    self.rect = self.sprite.get_rect()  # makes rectagle to put png on to interact with other things
    self.rect.x = WIDTH - 1150  #Rounded division and where the enemy first starts vertically
    self.rect.y = HEIGHT - 725       # where the enemy first starts vertically
    self.cooldown = 0

	# figure out logic to make it go to left of screen then go down one and then to the right and repeat 
  def update(self):
    self.cooldown += 1
    self.rect.move_ip(1,0)     


class Player(pg.sprite.Sprite):
  def __init__(self):      # constructor
    super(Player, self).__init__()     # super calls the parent class method (this case constructor)
    self.sprite = pg.image.load("Laser_Cannon.png")
    self.width = self.sprite.get_width() / 8
    self.height = self.sprite.get_height() / 8
    self.sprite = pg.transform.scale(self.sprite, ((self.width, self.height))) # resizes the image
    self.rect = self.sprite.get_rect()  # makes rectagle to put png on to interact with other things
    self.rect.x = WIDTH // 2 #Rounded division
    self.rect.y = HEIGHT // 1.1       # where the player is stationed
    self.cooldown = 0

  def update(self, pressed_keys):
    self.cooldown += 1         
    if (pressed_keys[K_RIGHT]):
      if(self.rect.x < 1143):
        self.rect.move_ip(1,0)
    elif (pressed_keys[K_LEFT]):
        if(self.rect.x > 0):
          self.rect.move_ip(-1,0)

    if (pressed_keys[K_UP]):
      if self.cooldown >= 250:
        bullet = Bullet()
        bullet.x = WIDTH // 2
        bullet.y = HEIGHT // 2
        bullet.rect.midbottom = self.rect.midbottom
        bullet.rect.y -= 30
        bulletGroup.add(bullet)
        self.cooldown = 0

    if (pressed_keys[K_SPACE]):
      if self.cooldown >= 1000:
        superBullet = SuperBullet()
        superBullet.x = WIDTH // 2
        superBullet.y = HEIGHT // 2
        superBullet.rect.midbottom = self.rect.midbottom
        superBullet.rect.y -= 30
        superBulletGroup.add(superBullet)
        self.cooldown = 0
      

  


player = Player()

enemy = Enemy()

screen = pg.display.set_mode((WIDTH, HEIGHT))

running = True

while running:
  for event in pg.event.get():
    if event.type == KEYDOWN:
        if event.key == K_ESCAPE:
            running = False

  pressed_keys = pg.key.get_pressed()

  player.update(pressed_keys)
  enemy.update()

  screen.fill((0,0,0))
  for bullet in bulletGroup:
      bullet.update()
      screen.blit(bullet.sprite, bullet.rect)
  for superBullet in superBulletGroup:
      superBullet.update()
      screen.blit(superBullet.sprite, superBullet.rect)
  screen.blit(player.sprite, player.rect)      # puts sprite (image and rectangle combo) onto screen (look up blit)
  screen.blit(enemy.sprite, enemy.rect)
  

  pg.display.flip()

