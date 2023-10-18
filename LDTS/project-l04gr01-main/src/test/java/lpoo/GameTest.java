package lpoo;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
public class GameTest {
    Game game;
    @BeforeEach
    void setUp() {
        game = new Game();
    }
        @Test
        void testGetSetWidth() {
            game.WIDTH = 1;
            Assertions.assertEquals(1, game.WIDTH);

        }
        @Test
        void testGetSetHeight() {
            game.HEIGHT = 1;
            Assertions.assertEquals(1, game.HEIGHT);

        }
        @Test
        void testGetSetGridSize() {
            game.GRID_SIZE = 1;
            Assertions.assertEquals(1, game.GRID_SIZE);

        }
        @Test
        void testGetSetMineCount() {
            game.MINE_COUNT = 1;
            Assertions.assertEquals(1, game.MINE_COUNT);

        }
}
