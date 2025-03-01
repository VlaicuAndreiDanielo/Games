# Hangman & The Bread - C++ Games

## Overview
This repository contains two games implemented in C++: **Hangman** and **The Bread**. Both games are designed to be played in the console and include various features that enhance the gameplay experience.

---

## 🕵️ Hangman (Spânzurătoarea)
A classic word-guessing game where the player must discover a hidden word by guessing letters. The game includes five difficulty levels, where the complexity increases based on the length of the words.

### **Features**
- The word is chosen randomly at the start of each game.
- Five difficulty levels, increasing based on word length.
- The game displays:
  - A visual representation of the hanging man when incorrect guesses are made.
  - Letters that have been used (both correct and incorrect).
  - The number of letters in the word.
- The player can guess the entire word directly at any time.
- Scoring system based on the number of incorrect guesses.

### **Winning & Losing**
- If the player correctly guesses the word, they win.
- If the drawing of the hanging man is completed before the word is guessed, the player loses.
- At the end, the final score is displayed based on the number of mistakes.

---

## 🍞 The Bread (Pâinica)
A unique number-guessing game where the player competes against the computer to guess a hidden number.

### **Game Modes**
- **Player guesses the computer's number**: The computer selects a number, and the player must guess it.
- **Computer guesses the player's number**: The player chooses a number, and the computer tries to guess it.

### **Rules**
- The game continues until either the player or the computer successfully guesses the number.
- If the player manages to guess the computer’s number three times OR prevents the computer from guessing their number three times, they win.

---

## 🎮 How to Run
You can compile and run the games using a C++ compiler.

