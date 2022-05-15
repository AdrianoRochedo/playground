# https://www.w3schools.com/python/python_datatypes.asp

# basico

x = 5

if x > 2:
  print("Hellow Adriano!")

#This is a comment.

"""
This is a comment
written in
more than just one line
"""

# CAST

x = str(3)    # x will be '3'
y = int(3)    # y will be 3
z = float(3)  # z will be 3.0

print (x)
print (y)
print (z)

print(x, y, z)

# GET THE TYPE

x = 5
y = "John"
print(type(x))
print(type(y))

# Unpack a Collection

fruits = ["apple", "banana", "cherry"]
x, y, z = fruits
print(x)
print(y)
print(z)

print(fruits)

# Global Variables

x = "awesome"

def myfunc():
  print("Python is " + x)

myfunc()

# Variables types

x = ["apple", "banana", "cherry"]               # list
x = ("apple", "banana", "cherry")               # tuple
x = range(6)                                    # range
x = {"name" : "John", "age" : 36}               # dict	
x = {"apple", "banana", "cherry"}               # set	
x = frozenset({"apple", "banana", "cherry"})    # frozenset	
x = True                                        # bool	
x = b"Hello"                                    # bytes	
x = bytearray(5)                                # bytearray	
x = memoryview(bytes(5))                        # memoryview	
x = None                                        # NoneType

# Multiline Strings

a = """Lorem ipsum dolor sit amet,
consectetur adipiscing elit,
sed do eiusmod tempor incididunt
ut labore et dolore magna aliqua."""

print(a)

# Looping Through a String

for x in "banana":
  print(x)

# String Length

x = "adriano"
print(len(x))

# Check String

txt = "The best things in life are free!"
if "free" in txt:
  print("Yes, 'free' is present.")

# string format

quantity = 3
itemno = 567
price = 49.95
myorder = "I want {} pieces of item {} for {} dollars."
print(myorder.format(quantity, itemno, price))

# Arbitrary Arguments, *args

def my_function(*kids):
  print("The youngest child is " + kids[2])

my_function("Emil", "Tobias", "Linus")

# Keyword Arguments

def my_function(child3, child2, child1):
  print("The youngest child is " + child3)

my_function(child1 = "Emil", child2 = "Tobias", child3 = "Linus")

# Arbitrary Keyword Arguments, **kwargs

def my_function(**kid):
  print("His last name is " + kid["lname"])

my_function(fname = "Tobias", lname = "Refsnes")

# Return Values

def my_function(x):
  return 5 * x

print(my_function(3))
print(my_function(5))
print(my_function(9))

# lambda

x = lambda a : a + 10
print(x(5))

def myfunc(n):
  return lambda a : a * n

mydoubler = myfunc(2)

print(mydoubler(11))

# classes

class Person:

  def __init__(self, name, age):
    self.name = name
    self.age = age

  def myfunc(self):
    print("Hello my name is " + self.name)
    
p1 = Person("John", 36)

print(p1.name)
print(p1.age)
p1.myfunc()


# classes => Inheritance

class Person:

  def __init__(self, fname, lname):
    self.firstname = fname
    self.lastname = lname

  def printname(self):
    print(self.firstname, self.lastname)

class Student(Person):

  def __init__(self, fname, lname):
    Person.__init__(self, fname, lname)

x = Student("Mike", "Olsen")
x.printname()

class Student(Person):

  def __init__(self, fname, lname):
    super().__init__(fname, lname)
    self.graduationyear = 2019

# modulos

import MeuModulo

MeuModulo.greeting("Jonathan")

# Built-in Modules

import platform

x = platform.system()
print(x)

from MeuModulo import person1

print (person1["age"])

# JSON

import json

# some JSON:
x =  '{ "name":"John", "age":30, "city":"New York"}'

# parse x:
y = json.loads(x)

# the result is a Python dictionary:
print(y["age"])

# a Python object (dict):
x = {
  "name": "John",
  "age": 30,
  "city": "New York"
}

# convert into JSON:
y = json.dumps(x)

# the result is a JSON string:
print(y)

# Convert Python objects into JSON strings, and print the values:

print(json.dumps({"name": "John", "age": 30}))
print(json.dumps(["apple", "bananas"]))
print(json.dumps(("apple", "bananas")))
print(json.dumps("hello"))
print(json.dumps(42))
print(json.dumps(31.76))
print(json.dumps(True))
print(json.dumps(False))
print(json.dumps(None))

# Exception Handling

try:
  print(x)
except NameError:
  print("Variable x is not defined")
except:
  print("Something else went wrong")
finally:
  print("The 'try except' is finished")

# Raise an exception

x = 10

if x < 0:
  raise Exception("Sorry, no numbers below zero")

# User Input

username = input("Enter username:")
print("Username is: " + username)

# pandas

import pandas as pd

mydataset = {
  'cars': ["BMW", "Volvo", "Ford"],
  'passings': [3, 7, 2]
}

myvar = pd.DataFrame(mydataset)

print(myvar)

# numPy

import numpy as np
from scipy.spatial import Delaunay
import matplotlib.pyplot as plt

points = np.array([
  [2, 4],
  [3, 4],
  [3, 0],
  [2, 2],
  [4, 1]
])

simplices = Delaunay(points).simplices

plt.triplot(points[:, 0], points[:, 1], simplices)
plt.scatter(points[:, 0], points[:, 1], color='r')

plt.show()


















