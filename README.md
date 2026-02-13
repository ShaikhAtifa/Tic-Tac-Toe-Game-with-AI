# Tic-Tac-Toe-Game-with-AI
This project is a console-based Tic Tac Toe game implemented in C, where a human plays against an AI.
The AI uses the Minimax algorithm to always choose the optimal move, making it impossible to beat.


Features
Human vs AI Gameplay
AI implemented using the Minimax algorithm
Depth-Based Scoring for Faster Wins and Delayed Losses
Unbeatable AI (plays optimally
Clear display of a 3×3
Input Validation for Illegal Moves
Detects conditions for winning, losing, and drawing

Algorithm Used – Minimax
The Minimax algorithm is a recursive decision-making algorithm for two-player turn-based game situations.
Maximizer → AI ('O')
Minimizer → Player ('X')
Evaluates all possible future game states
Assigns scores:
+10 → AI win
-10 Player win
0 → Draw
Depth is added/subtracted to prioritize quicker wins and slower losses.
