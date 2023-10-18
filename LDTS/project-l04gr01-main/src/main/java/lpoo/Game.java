package lpoo;

public class Game {

    public static int WIDTH = 720, HEIGHT = 720; // Window size
    public static int GRID_SIZE = 10; // Grid size (10 by 10)
    public static int MINE_COUNT = (int) Math.round(GRID_SIZE * GRID_SIZE * 0.1); // Number of mines

    private Handler handler = new Handler();

    public Game() {
        new Window(WIDTH, HEIGHT, GRID_SIZE, "Minesweeper", this, handler);
        Window.update(0);
    }

    public static void main(String[] args) {
        new Game();
    }

}
