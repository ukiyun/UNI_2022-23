package lpoo;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Grid extends JPanel {

    private int bound = Game.GRID_SIZE*Game.GRID_SIZE; // Number of cells in the grid

    private boolean picked = false; // If the player has picked a cell

    private ArrayList<Integer> mines = new ArrayList<Integer>(); // List of mines

    public static ArrayList<Cell> cellGrid = new ArrayList<Cell>(); // Holds every cell in the grid

    public Grid(GridLayout g, Handler h){
        super(g);
        createCells(h);
        addCells();
    }

    public void createCells(Handler h){
        for(int i = 1; i <= Game.MINE_COUNT; i++) {
            while (!picked) {
                int minePosition = (int) (Math.random() * bound); // Random position for the mine
                if (!mines.contains(minePosition)) { // If the mine position is not already in the list
                    mines.add(minePosition); // Add the mine position to the list
                    picked = true; // The mine position has been picked
                }
            }
            picked = false; // Reset the picked variable
        }
        for(int i = 0; i < bound ; i++){
            if(mines.contains(i)){
                cellGrid.add(new Cell(1, i, false, false, h)); // Add a mine to the grid
            } else if(i % Game.GRID_SIZE == 0) {  //left edge of the grid
                if(mines.contains(i - Game.GRID_SIZE) ||
                        mines.contains(i - Game.GRID_SIZE +1)||
                        mines.contains(i + 1)||
                        mines.contains(i + Game.GRID_SIZE)||
                        mines.contains(i + Game.GRID_SIZE +1)){
                    cellGrid.add(new Cell(2, i, false, false, h)); // Add a number to the grid
                }else {
                    cellGrid.add(new Cell(0, i, false, false, h)); // Add an empty cell to the grid
                }
            }else if(i % Game.GRID_SIZE == Game.GRID_SIZE - 1){ //right edge of the grid
                if(mines.contains(i - Game.GRID_SIZE -1) ||
                        mines.contains(i - Game.GRID_SIZE) ||
                        mines.contains(i - 1)||
                        mines.contains(i + Game.GRID_SIZE -1)||
                        mines.contains(i + Game.GRID_SIZE)){
                    cellGrid.add(new Cell(2, i, false, false, h)); // Add a number to the grid
                }else {
                    cellGrid.add(new Cell(0, i, false, false, h)); // Add an empty cell to the grid
                }
            }else{
                if(mines.contains(i - Game.GRID_SIZE -1) ||     //checking if cells around are mines
                        mines.contains(i - Game.GRID_SIZE) ||
                        mines.contains(i - Game.GRID_SIZE +1)||
                        mines.contains(i - 1)||
                        mines.contains(i + 1)||
                        mines.contains(i + Game.GRID_SIZE -1)||
                        mines.contains(i + Game.GRID_SIZE)||
                        mines.contains(i + Game.GRID_SIZE +1)){
                    cellGrid.add(new Cell(2, i, false, false, h)); // Add a number to the grid
                }else {
                    cellGrid.add(new Cell(0, i, false, false, h)); // Add an empty cell to the grid
                }
            }
        }
    }

    private void addCells(){
        for(int i = 0; i < cellGrid.size(); i++){
            add(cellGrid.get(i));
        }
    }

}
