
//Classes
public class Button {
  String id;
  //Button Text
  String text;
  PFont font;
  int size;
  //Button placement and dimensions
  int x, y, w, h;
  //mouse pointer tracking
  int mX, mY;
  //graphics data
  color currentColor;
  color activeColor;
  color hoverColor;

  Button(String i) {
    this.id = i; 
  }
  
  void setActiveColor(color newColor) {
    this.activeColor = newColor;
  }
  
  void setHoverColor(color newColor) {
    this.hoverColor = newColor;
  }
  
  void setDimensions(int x, int y, int w, int h) {
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
  }

  void setText(String t, PFont font, int size) {
    this.text = t;
    this.font = font;
    this.size = size;
  } 

  void drawButton() {
    textAlign(LEFT, BASELINE);
    noStroke();
    fill(currentColor);
    rect(this.x, this.y, this.w, this.h, 5);
    fill(textColor);
    textFont(font, size);
    text(text, this.x + 10, this.y + size);
  }

  void update() {
    if (this.overButton()) {
      this.currentColor = this.hoverColor;
    } else {
      this.currentColor = this.activeColor;
    }
  }

  boolean overButton() {
    if (mouseX >= this.x && mouseX <= this.x + this.w && 
      mouseY >= this.y && mouseY <= this.y + this.h) {
      return true;
    } else {
      return false;
    }
  }
}