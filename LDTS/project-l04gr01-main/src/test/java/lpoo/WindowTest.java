package lpoo;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.mockito.Mockito;
public class WindowTest {
    Window window;
    Window stubWindow;

    @BeforeEach
    void setUp() {
        stubWindow = Mockito.mock(Window.class);
        Mockito.when(stubWindow.getWidth()).thenReturn(1);
        Mockito.when(stubWindow.getHeight()).thenReturn(1);
        Mockito.when(stubWindow.getGridSize()).thenReturn(1);
        Mockito.when(stubWindow.getTitle()).thenReturn("title");

        window = new Window(stubWindow.getWidth(), stubWindow.getHeight(), stubWindow.getGridSize(), stubWindow.getTitle(), null, null);
    }

    @Test
    void testGetSetWidth() {
        window.setWidth(1);
        Assertions.assertEquals(1, window.getWidth());
    }

    @Test
    void testGetSetHeight() {
        window.setHeight(1);
        Assertions.assertEquals(1, window.getHeight());
    }

    @Test
    void testGetSetGridSize() {
        window.setGridSize(1);
        Assertions.assertEquals(1, window.getGridSize());
    }

    @Test
    void testGetSetTitle() {
        window.setTitle("New Title");
        Assertions.assertEquals("New Title", window.getTitle());
    }

}
