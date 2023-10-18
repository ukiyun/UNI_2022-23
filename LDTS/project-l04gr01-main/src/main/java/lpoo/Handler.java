package lpoo;

import java.util.ArrayList;

public class Handler {

    private ArrayList<Cell> curr = new ArrayList<Cell>();
    private ArrayList<Cell> queue = new ArrayList<Cell>();

    private static int flaggedCells = 0;

    public void click(Cell cell) {

        int discoveredCells = 0;
        if(!cell.isFlagged()) {
            cell.setEnabled(false);
            cell.setDiscovered(true);
        
            int position = cell.getPosition();
            if (cell.getType() == 0) {
                if(position < Game.GRID_SIZE) {
                    if(position % Game.GRID_SIZE == 0) {
                        queue.add(Grid.cellGrid.get(position + Game.GRID_SIZE));
                        queue.add(Grid.cellGrid.get(position + Game.GRID_SIZE + 1));
                        queue.add(Grid.cellGrid.get(position + 1));
                    } else if(position % Game.GRID_SIZE == Game.GRID_SIZE -1) {
                        queue.add(Grid.cellGrid.get(position + Game.GRID_SIZE));
                        queue.add(Grid.cellGrid.get(position + Game.GRID_SIZE - 1));
                        queue.add(Grid.cellGrid.get(position - 1));
                    } else {
                        queue.add(Grid.cellGrid.get(position + Game.GRID_SIZE));
                        queue.add(Grid.cellGrid.get(position + Game.GRID_SIZE + 1));
                        queue.add(Grid.cellGrid.get(position + Game.GRID_SIZE - 1));
                        queue.add(Grid.cellGrid.get(position - 1));
                        queue.add(Grid.cellGrid.get(position + 1));
                    }

                } else if(position >= Game.GRID_SIZE * (Game.GRID_SIZE - 1)) {
                    if(position % Game.GRID_SIZE == 0) {
                        queue.add(Grid.cellGrid.get(position - Game.GRID_SIZE));
                        queue.add(Grid.cellGrid.get(position - Game.GRID_SIZE + 1));
                        queue.add(Grid.cellGrid.get(position + 1));
                    } else if(position % Game.GRID_SIZE == Game.GRID_SIZE -1) {
                        queue.add(Grid.cellGrid.get(position - Game.GRID_SIZE));
                        queue.add(Grid.cellGrid.get(position - Game.GRID_SIZE - 1));
                        queue.add(Grid.cellGrid.get(position - 1));
                    } else {
                        queue.add(Grid.cellGrid.get(position - Game.GRID_SIZE));
                        queue.add(Grid.cellGrid.get(position - Game.GRID_SIZE + 1));
                        queue.add(Grid.cellGrid.get(position - Game.GRID_SIZE - 1));
                        queue.add(Grid.cellGrid.get(position - 1));
                        queue.add(Grid.cellGrid.get(position + 1));
                    }

                } else if (position % Game.GRID_SIZE == 0) {
                    queue.add(Grid.cellGrid.get(position - Game.GRID_SIZE));
                    queue.add(Grid.cellGrid.get(position + Game.GRID_SIZE));
                    queue.add(Grid.cellGrid.get(position - Game.GRID_SIZE + 1));
                    queue.add(Grid.cellGrid.get(position + Game.GRID_SIZE + 1));
                    queue.add(Grid.cellGrid.get(position + 1));

                } else if (position % Game.GRID_SIZE == Game.GRID_SIZE - 1) {
                    queue.add(Grid.cellGrid.get(position - Game.GRID_SIZE));
                    queue.add(Grid.cellGrid.get(position + Game.GRID_SIZE));
                    queue.add(Grid.cellGrid.get(position - Game.GRID_SIZE - 1));
                    queue.add(Grid.cellGrid.get(position + Game.GRID_SIZE - 1));
                    queue.add(Grid.cellGrid.get(position - 1));

                } else {
                    queue.add(Grid.cellGrid.get(position - Game.GRID_SIZE));
                    queue.add(Grid.cellGrid.get(position + Game.GRID_SIZE));
                    queue.add(Grid.cellGrid.get(position - Game.GRID_SIZE - 1));
                    queue.add(Grid.cellGrid.get(position + Game.GRID_SIZE - 1));
                    queue.add(Grid.cellGrid.get(position - Game.GRID_SIZE + 1));
                    queue.add(Grid.cellGrid.get(position + Game.GRID_SIZE + 1));
                    queue.add(Grid.cellGrid.get(position - 1));
                    queue.add(Grid.cellGrid.get(position + 1));
                }

            } else if (cell.getType() == 2) {
                int dangerCount = 0;
                if(position < Game.GRID_SIZE) {
                    if(position % Game.GRID_SIZE == 0) {
                        if(Grid.cellGrid.get(position + Game.GRID_SIZE).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position + Game.GRID_SIZE + 1).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position + 1).getType() == 1) dangerCount++;

                    } else if(position % Game.GRID_SIZE == Game.GRID_SIZE - 1) {
                        if(Grid.cellGrid.get(position + Game.GRID_SIZE).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position + Game.GRID_SIZE - 1).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position - 1).getType() == 1) dangerCount++;

                    } else {
                        if(Grid.cellGrid.get(position + Game.GRID_SIZE).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position + Game.GRID_SIZE + 1).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position + Game.GRID_SIZE - 1).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position + 1).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position - 1).getType() == 1) dangerCount++;

                    }

                } else if(position >= Game.GRID_SIZE * (Game.GRID_SIZE - 1)) {
                    if(position % Game.GRID_SIZE == 0) {
                        if(Grid.cellGrid.get(position - Game.GRID_SIZE).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position - Game.GRID_SIZE + 1).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position + 1).getType() == 1) dangerCount++;

                    } else if(position % Game.GRID_SIZE == Game.GRID_SIZE - 1) {
                        if(Grid.cellGrid.get(position - Game.GRID_SIZE).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position - Game.GRID_SIZE - 1).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position - 1).getType() == 1) dangerCount++;

                    } else {
                        if(Grid.cellGrid.get(position - Game.GRID_SIZE).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position - Game.GRID_SIZE + 1).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position - Game.GRID_SIZE - 1).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position + 1).getType() == 1) dangerCount++;
                        if(Grid.cellGrid.get(position - 1).getType() == 1) dangerCount++;

                    }

                } else if(position % Game.GRID_SIZE == 0) {
                    if(Grid.cellGrid.get(position - Game.GRID_SIZE).getType() == 1) dangerCount++;
                    if(Grid.cellGrid.get(position + Game.GRID_SIZE).getType() == 1) dangerCount++;
                    if(Grid.cellGrid.get(position - Game.GRID_SIZE + 1).getType() == 1) dangerCount++;
                    if(Grid.cellGrid.get(position + Game.GRID_SIZE + 1).getType() == 1) dangerCount++;
                    if(Grid.cellGrid.get(position + 1).getType() == 1) dangerCount++;
                    

                } else if (position % Game.GRID_SIZE == Game.GRID_SIZE - 1) {
                    if(Grid.cellGrid.get(position - Game.GRID_SIZE).getType() == 1) dangerCount++;
                    if(Grid.cellGrid.get(position + Game.GRID_SIZE).getType() == 1) dangerCount++;
                    if(Grid.cellGrid.get(position - Game.GRID_SIZE - 1).getType() == 1) dangerCount++;
                    if(Grid.cellGrid.get(position + Game.GRID_SIZE - 1).getType() == 1) dangerCount++;
                    if(Grid.cellGrid.get(position - 1).getType() == 1) dangerCount++;

                } else {
                    if(Grid.cellGrid.get(position - Game.GRID_SIZE).getType() == 1) dangerCount++;
                    if(Grid.cellGrid.get(position + Game.GRID_SIZE).getType() == 1) dangerCount++;
                    if(Grid.cellGrid.get(position - Game.GRID_SIZE - 1).getType() == 1) dangerCount++;
                    if(Grid.cellGrid.get(position + Game.GRID_SIZE - 1).getType() == 1) dangerCount++;
                    if(Grid.cellGrid.get(position - Game.GRID_SIZE + 1).getType() == 1) dangerCount++;
                    if(Grid.cellGrid.get(position + Game.GRID_SIZE + 1).getType() == 1) dangerCount++;
                    if(Grid.cellGrid.get(position - 1).getType() == 1) dangerCount++;
                    if(Grid.cellGrid.get(position + 1).getType() == 1) dangerCount++;

                }
                cell.setText(String.valueOf(dangerCount));

            } else if (cell.getType() == 1) {
                for(int x = 0; x < Grid.cellGrid.size(); x++) {
                    Grid.cellGrid.get(x).setEnabled(false);
                    Grid.cellGrid.get(x).setText("");
                    if(Grid.cellGrid.get(x).getType() == 1) { Grid.cellGrid.get(x).setText("X"); }
                }
                cell.setText("X");
            }

            for(int x = 0; x < queue.size(); x++) {
                if(!queue.get(x).isDiscovered()) {
                    curr.add(queue.get(x));
                    queue.get(x).setDiscovered(true);
                }
            }
            queue.clear();
            while(!curr.isEmpty()) {
                Cell aux = curr.get(0);
                curr.remove(0);
                aux.clickButton();
            }

            for(int x = 0; x < Grid.cellGrid.size(); x++) {
                if(Grid.cellGrid.get(x).isDiscovered()) {
                    discoveredCells++;
                }
            }

            if(discoveredCells == Grid.cellGrid.size() - Game.MINE_COUNT) {
                for(int x = 0; x < Grid.cellGrid.size(); x++) {
                    if(Grid.cellGrid.get(x).getType() == 1) {
                        Grid.cellGrid.get(x).setEnabled(false);
                        Grid.cellGrid.get(x).setText("WIN!");
                    } else {
                        Grid.cellGrid.get(x).setEnabled(false);
                        Grid.cellGrid.get(x).setText("WIN!");
                    }
                }
            }
        }
    }

    public void rightClick(Cell cell) {
        if(!cell.isDiscovered()) {
            if(!cell.isFlagged()) {
                cell.setFlagged(true);
                cell.setText("F");
                flaggedCells++;
                Window.update(flaggedCells);
            } else {
                cell.setFlagged(false);
                cell.setText("");
                flaggedCells--;
                Window.update(flaggedCells);
            }
        }
    }
}
