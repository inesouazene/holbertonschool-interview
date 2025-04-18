Lockboxes

Description

This project contains a solution to the lockboxes problem. The problem involves determining if all locked boxes can be opened given that each box may contain keys to other boxes.

Requirements

All files will be interpreted/compiled on Ubuntu 14.04 LTS using python3 (version 3.4.3)
All files should end with a new line
The first line of all files should be exactly #!/usr/bin/python3
Code follows the PEP 8 style (version 1.7.x)
All files must be executable

Task: Lockboxes

File: 0-lockboxes.py
Function: canUnlockAll(boxes)
Description: Determines if all boxes can be opened.

Problem Statement
You have n number of locked boxes in front of you. Each box is numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes. Write a method that determines if all the boxes can be opened.
Function Prototype
pythondef canUnlockAll(boxes)
Parameters

boxes is a list of lists
A key with the same number as a box opens that box
You can assume all keys will be positive integers
There can be keys that do not have boxes
The first box boxes[0] is unlocked

Return

True if all boxes can be opened, else return False