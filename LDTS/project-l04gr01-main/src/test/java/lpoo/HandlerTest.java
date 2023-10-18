package lpoo;

import lpoo.Cell;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.mockito.Mockito;

public class HandlerTest {

    Handler handler;
    Cell cell;
    Cell stubCell;
    int flaggedCells = 0;

    @BeforeEach
    void setUp() {
        stubCell = Mockito.mock(Cell.class);
        Mockito.when(stubCell.getType()).thenReturn(1);
        Mockito.when(stubCell.getPosition()).thenReturn(1);
        Mockito.when(stubCell.isDiscovered()).thenReturn(false);
        Mockito.when(stubCell.isFlagged()).thenReturn(false);

        cell = new Cell(stubCell.getPosition(), stubCell.getType(), stubCell.isDiscovered(), stubCell.isFlagged(), handler);
    }

    @Test
    void testRightClick() {
        handler.rightClick(cell);
        Assertions.assertEquals(1, flaggedCells);
    }
}
