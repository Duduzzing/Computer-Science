
package flappybird;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.Timer;

public class FlappyBird implements ActionListener, MouseListener, KeyListener {

  public static FlappyBird flappyBird;

  public static final int WIDTH = 800, HEIGHT = 800;

  public Renderer renderer;

  public Bird[] birds, bestPop;

  public int population = 1000;

  public int generation = 1;

  // if true, the bird in that index is dead
  public Boolean[] deadPopulation = new Boolean[population];

  public int deadAmount = 0;

  public ArrayList<Rectangle> columns;

  public boolean gameOver, started;

  public int groundHeight = 120;

  // gap between top and bottom columns
  public int space = 300;

  public int distanceBetweenColumns = 600;

  public float bestFit = -500;
  public float lastFit = 0;

  public int bestScore = 0;
  public int lastScore = 0;

  int initialSpeed = 10;
  int speed = initialSpeed;
  int maxSpeed = 15;
  // every this point, speed++
  int speedPerScore = 20;

  public FlappyBird() {

    JFrame jframe = new JFrame();
    Timer timer = new Timer(20, this);

    renderer = new Renderer();

    jframe.add(renderer);
    jframe.setTitle("Flappy Bird");
    jframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    jframe.setSize(WIDTH, HEIGHT);
    jframe.addMouseListener(this);
    jframe.addKeyListener(this);
    jframe.setResizable(false);
    jframe.setVisible(true);

    birds = new Bird[population];
    bestPop = new Bird[population];

    for (int i = 0; i < birds.length; i++) {

      birds[i] = new Bird();
      deadPopulation[i] = false;

    }

    columns = new ArrayList<>();

    addColumn(true);
    addColumn(true);

    timer.start();
  }

  public void addColumn(boolean start) {

    int width = 100;
    int height = 100 + Util.nextInt(300);

    if (start) {

      // btm
      columns.add(new Rectangle(WIDTH + width + columns.size() * 300,
              HEIGHT - height - groundHeight,
              width, height));

      // top
      columns.add(new Rectangle(columns.get(columns.size() - 1).x, 0,
              width, HEIGHT - height - space));

    } else {

      Rectangle prevCol = columns.get(columns.size() - 1);

      columns.add(new Rectangle(prevCol.x + distanceBetweenColumns,
              HEIGHT - height - groundHeight,
              width, height));

      prevCol = columns.get(columns.size() - 1);

      columns.add(new Rectangle(prevCol.x, 0,
              width, HEIGHT - height - space));

    }

  }

  public void paintColumn(Graphics g, Rectangle column) {

    g.setColor(Color.green.darker());
    g.fillRect(column.x, column.y, column.width, column.height);
  }

  /**
   * Restart from scratch
   */
  public void restartGame() {

    resetGame(false);

  }

  @Override
  public void actionPerformed(ActionEvent e) {

    if (gameOver) {

      resetGame(true);

      generation++;

      return;

    }

    if (started) {

      for (int i = 0; i < columns.size(); i++) {

        Rectangle column = columns.get(i);
        column.x -= speed;

        // out of screen
        if (column.x + column.width < 0) {
          columns.remove(column);

          // occur only once for each set of columns
          // add new ones
          if (column.y == 0) {
            addColumn(false);
          }
        }
      }

      boolean isSpedUp = false;

      for (int i = 0; i < birds.length; i++) {

        // skip the dead one
        if (deadPopulation[i])
          continue;

        Rectangle column1 = columns.get(0);

        // the index of the bottom column that's in front of bird
        int colIndex = 0;

        if (column1.x < 0)
          colIndex = 2;

        int disToGap = columns.get(colIndex).x - birds[i].bounds.x;
        int gapDeltaY = birds[i].getVerticalGapDis(columns.get(colIndex), space,
                false);

        float input1 = Util.normalize((float) disToGap,
                (float) distanceBetweenColumns);
        float input2 = Util.normalize((float) gapDeltaY, (float) HEIGHT / 2);

        float input3 = Util.normalize((float) speed, (float) maxSpeed);

        birds[i].fall();
        birds[i].act(new float[]{input1, input2, input3});

        // we only care about the four columns in the screen
        for (int j = 0; j < columns.size(); j++) {

          Rectangle column = columns.get(j);

          if (column.x < 0)
            continue;

          int birdx = birds[i].bounds.x + birds[i].bounds.width / 2;
          int columnCenter = column.x + column.width / 2;
          int birdCenter = Bird.SIZE / 2;

          if (column.y == 0
                  && birdx > columnCenter - birdCenter
                  && birdx < columnCenter + birdCenter) {

            // to prevent counting score more than once
            if (birds[i].lastColumnPassed == null || !birds[i].lastColumnPassed.
                    equals(column)) {

              birds[i].lastColumnPassed = column;

              birds[i].score++;

              if (!isSpedUp && speed < maxSpeed && birds[i].score % speedPerScore == 0) {
                isSpedUp = true;
                speed++;
              }
            }

          }

          // if hit column
          if (column.intersects(birds[i].bounds)) {
            deadPopulation[i] = true;

            int jj = j;
            if (j > 0)
              jj = 2;

            birds[i].calcFitness(columns.get(jj), space);

          }

        }

        // if hit top or bottom
        if (birds[i].bounds.y > HEIGHT - groundHeight || birds[i].bounds.y < 0) {
          deadPopulation[i] = true;
          birds[i].calcFitness(columns.get(colIndex), space);
        }

        // if hit bottom
        if (birds[i].bounds.y + birds[i].getMotionY() >= HEIGHT - groundHeight) {
          deadPopulation[i] = true;
          birds[i].calcFitness(columns.get(colIndex), space);
        }

        if (deadPopulation[i]) {

          deadAmount++;

          // if all died
          if (deadAmount == population)
            gameOver = true;

        }
      }
    }
    renderer.repaint();
  }

  public void repaint(Graphics g) {

    g.setColor(Color.cyan);
    g.fillRect(0, 0, WIDTH, HEIGHT);

    g.setColor(Color.orange);
    g.fillRect(0, HEIGHT - 100, WIDTH, 100);

    g.setColor(Color.green);
    g.fillRect(0, HEIGHT - 120, WIDTH, 20);

    g.setFont(new Font("Arial", 1, 20));

    for (int i = 0; i < birds.length; i++) {

      if (deadPopulation[i])
        continue;

      g.setColor(birds[i].getColor());
      g.fillRect(birds[i].bounds.x, birds[i].bounds.y,
              birds[i].bounds.width, birds[i].bounds.height);

      g.setColor(Color.BLACK);
      g.drawString(String.valueOf(birds[i].score), birds[i].bounds.x,
              birds[i].bounds.y);

    }

    for (Rectangle column : columns) {
      paintColumn(g, column);
    }

    g.setColor(Color.BLACK);

    g.drawString("Gen: " + generation, WIDTH / 2 + 30, 120);
    g.drawString("Dead: " + deadAmount + "/" + population, WIDTH / 2 + 30, 160);

    g.drawString("Best Fitness: " + bestFit, WIDTH / 2 + 30, 200);
    g.drawString("Last Gen's Fitness: " + lastFit, WIDTH / 2 + 30, 240);

    g.drawString("Best Score: " + bestScore, WIDTH / 2 + 30, 280);
    g.drawString("Last Gen's Score: " + lastScore, WIDTH / 2 + 30, 320);

    if (!started) {
      g.drawString("Click to start!", 75, HEIGHT / 2 - 50);
    }

    if (gameOver) {
      g.drawString("Game Over!", WIDTH / 2 - 100, HEIGHT / 2 - 50);
    }

  }

  public static void main(String[] args) {

    flappyBird = new FlappyBird();

  }

  @Override
  public void mouseClicked(MouseEvent e) {

    restartGame();

    started = true;
  }

  @Override
  public void keyReleased(KeyEvent e) {

    if (e.getKeyCode() == KeyEvent.VK_SPACE) {
      restartGame();
      started = true;
    }

  }

  @Override
  public void mousePressed(MouseEvent e) {

  }

  @Override
  public void mouseReleased(MouseEvent e) {

  }

  @Override
  public void mouseEntered(MouseEvent e) {

  }

  @Override
  public void mouseExited(MouseEvent e) {

  }

  @Override
  public void keyTyped(KeyEvent e) {

  }

  @Override
  public void keyPressed(KeyEvent e) {

  }

  private void resetGame(boolean isNewGen) {

    if (isNewGen) {

      // top three gets to breed
      Bird[] rank = new Bird[3];

      // just put some birds to start comparing
      rank[0] = birds[0];
      rank[1] = birds[1];
      rank[2] = birds[2];

      for (int i = 0; i < birds.length; i++) {

        // get the best three
        if (birds[i].getFitness() > rank[0].getFitness()) {
          rank[2] = rank[1];
          rank[1] = rank[0];
          rank[0] = birds[i];
        }

        deadPopulation[i] = false;
      }

      lastFit = rank[0].getFitness();

      if (rank[0].getFitness() > bestFit) {
        bestFit = rank[0].getFitness();
      }

      lastScore = rank[0].score;

      if (rank[0].score > bestScore) {
        bestScore = rank[0].score;
      }

      // new gen ///////////////////
      int odd = 10;

      // too good to mix its royal blood
      if ((float) rank[0].getFitness() / (float) bestFit > 1.5) {
        odd = 15;
        System.out.println("outstanding bird in gen: " + generation);
      }

      // if this generation is not that worse than the best one
      if ((float) bestFit / (float) rank[0].getFitness() < 0.5) {

        System.out.
                println("Gen: " + generation + " is weak, clone the best gen");
        birds = bestPop.clone();

        for (int i = 0; i < birds.length; i++) {

          // get the best three
          if (birds[i].getFitness() > rank[0].getFitness()) {
            rank[2] = rank[1];
            rank[1] = rank[0];
            rank[0] = birds[i];
          }

        }

      }

      for (int i = 0; i < birds.length; i++) {

        int rand = Util.nextInt(odd);

        Bird p1, p2;

        if (rand > 4)
          p1 = rank[0];
        else if (rand > 1)
          p1 = rank[1];
        else
          p1 = rank[2];

        rand = Util.nextInt(odd);

        if (rand > 4)
          p2 = rank[1];
        else if (rand > 1)
          p2 = rank[0];
        else
          p2 = rank[2];

        birds[i] = Bird.crossover(p1, p2);
        bestPop[i] = (Bird) birds[i].clone();

      }

      rank[0].resetPos();

      // take the best one to next generation directly
      birds[birds.length - 1] = rank[0];

    }

    columns.clear();

    deadAmount = 0;
    speed = initialSpeed;

    addColumn(true);
    addColumn(true);

    if (!isNewGen) {
      gameOver = false;
      started = false;
    } else {
      gameOver = false;
      started = true;
    }

  }

}
