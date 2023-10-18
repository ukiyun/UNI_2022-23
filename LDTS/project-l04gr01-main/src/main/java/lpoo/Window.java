package lpoo;

import javax.swing.*;
import java.awt.*;

public class Window {

    private static JFrame frame;
    private static String title;
    private int width;
    private int height;
    private int gridSize;

    public Window(int width, int height, int gridsize, String title, Game game, Handler handler) {
        this.width = width;
        this.height = height;
        this.gridSize = gridsize;
        this.title = title;
        Window.title = title;
        frame = new JFrame(title);
        frame.setPreferredSize(new Dimension(width, height)); // Window size
        frame.setMaximumSize(new Dimension(width, height));
        frame.setMinimumSize(new Dimension(width, height));
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);

        JPanel panel = new Grid(new GridLayout(gridsize, gridsize), handler); // Grid size

        frame.setContentPane(panel);
        frame.pack();
        frame.setVisible(true);
    }

    public int getWidth() {return width;}
    public void setWidth(int width) {this.width = width;}

    public int getHeight() {return height;}
    public void setHeight(int height) {this.height = height;}

    public int getGridSize() {return gridSize;}
    public void setGridSize(int gridSize) {this.gridSize = gridSize;}

    public String getTitle() {return title;}
    public void setTitle(String title) {this.title = title;}

    public static void update(int flagged) {
        frame.setTitle(title + " :: Number of Mines: " + Game.MINE_COUNT + " - Flags Used: " + flagged);
    }

}
