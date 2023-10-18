package lpoo;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;


public class CellTest {
    Cell cell;

    @BeforeEach
    void setUp() {
        cell = new Cell(0, 0, false, false, null);
    }
        @Test
        void testGetSetFlag() {
            cell.setFlagged(true);
            Assertions.assertEquals(true, cell.isFlagged());
               
        }

        @Test
        void testGetSetDiscovered() {
            cell.setDiscovered(true);
            Assertions.assertEquals(true, cell.isDiscovered());

        }

        @Test
        void testGetSetType() {
            cell.setType(1);
            Assertions.assertEquals(1, cell.getType());
        }

        @Test
        void testGetSetPosition() {
            cell.setPosition(1);
            Assertions.assertEquals(1, cell.getPosition());
        }
}
