package lpoo;

import javax.swing.*;
import java.awt.event.*;

public class Cell extends JButton {  //A cell is a JButton

    private int type; // 0 = empty, 1 = mine, 2 = number
    private int position; // Position in the grid
    private boolean discovered; // If the cell has been discovered
    private boolean flagged; // If the cell has been flagged

    private Handler handler;

    public Cell(int type, int position, boolean discovered, boolean flagged, Handler handler) {  //Constructor
        this.type = type;
        this.position = position;
        this.discovered = discovered;
        this.flagged = flagged;
        this.handler = handler;

        addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if(SwingUtilities.isRightMouseButton(e)) {
                    rightClickButton();
                } else {
                    clickButton();
                }
            }

            public void mouseEntered(MouseEvent e) {}
            public void mouseExited(MouseEvent e) {}
            public void mousePressed(MouseEvent e) {}
            public void mouseReleased(MouseEvent e) {}
        });
    }

    //Getters and setters

    public int getType() {
        // 0 = Empty, 1 = Mine, 2 = Number
        return type;
    }

    public void setType(int type) {this.type = type;}
    public int getPosition() {
        return position;
    }

    public void setPosition(int position) {this.position = position;}

    public boolean isDiscovered() {
        return discovered;
    }

    public void setDiscovered(boolean discovered) {
        this.discovered = discovered;
    }

    public boolean isFlagged() {
        return flagged;
    }

    public void setFlagged(boolean flagged) {
        this.flagged = flagged;
    }

    public void clickButton() {
        handler.click(this);
    }

    public void rightClickButton() {
        handler.rightClick(this);
    }

}
