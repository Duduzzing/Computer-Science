
package flappybird;

import java.awt.Color;
import java.awt.Rectangle;

public class Bird {

  /**
   * Physical Size
   */
  public static final int SIZE = 20;

  /**
   * Number of inputs this receives
   */
  private static final int INPUT_AMOUNT = 3;

  /**
   * Number of perceptrons in that index's hidden layer
   */
  private static final int[] HIDDEN_LAYER_AMOUNT = {6, 3};

  /**
   * Number of output perceptrons
   */
  private static final int OUTPUT_AMOUNT = 1;

  /**
   * Rate of learning per training.
   * Lower the more precise it gets, but learning speed slow down.
   */
  private static final float LEARNING_RATE = 0.1f;

  private static final float MUTATION_RATE = 0.01f;

  private static final int ACCELERATION = 1;

  private float fitness;

  private NeuralNetwork network;

  public Rectangle bounds;

  private int motionY = 0;

  private int distance = 0;

  public int score = 0;

  private Color color;

  // to prevent counting score more than once
  public Rectangle lastColumnPassed = null;

  public Bird() {

    //this.network = new NeuralNetwork();
    this.fitness = 0;

    this.bounds = new Rectangle(FlappyBird.WIDTH / 2 - SIZE / 2,
            FlappyBird.HEIGHT / 2 - SIZE / 2, SIZE, SIZE);

    network = new NeuralNetwork(INPUT_AMOUNT, HIDDEN_LAYER_AMOUNT,
            OUTPUT_AMOUNT, LEARNING_RATE, MUTATION_RATE, false);

    color = new Color(Util.nextInt(256), Util.nextInt(256), Util.nextInt(256));

  }

  public void resetPos() {

    this.bounds.x = FlappyBird.WIDTH / 2 - SIZE / 2;
    this.bounds.y = FlappyBird.HEIGHT / 2 - SIZE / 2;
    distance = 0;
    setScore(0);
    lastColumnPassed = null;

  }

  public void fall() {

    if (motionY < 15)
      motionY += ACCELERATION;

    bounds.y += motionY;

  }

  public void act(float[] inputs) {

    // Even though the outputs are in array, the bird has only one output perceptron
    // so I will not bother using for loop here
    float output = network.getOutputs(inputs)[0];

    distance++;

    // jump and reset falling velocity
    if (output > 0.5) {
      motionY = 0;
      bounds.y -= 30;
    }

  }

  /**
   * Mix the gene
   *
   * @param p1 parent
   * @param p2 parent
   * @return
   */
  public static Bird crossover(Bird p1, Bird p2) {

    Bird child = new Bird();

    // + 1 is the output layer
    Perceptron[][] childLayers = new Perceptron[HIDDEN_LAYER_AMOUNT.length + 1][];

    Perceptron[][] p1Layers = p1.getNetwork().getLayers();
    Perceptron[][] p2Layers = p2.getNetwork().getLayers();

    for (int y = 0; y < p1Layers.length; y++) {

      childLayers[y] = new Perceptron[p1Layers[y].length];

      for (int x = 0; x < p1Layers[y].length; x++) {

        Perceptron parentPerceptron1 = p1Layers[y][x];
        Perceptron parentPerceptron2 = p2Layers[y][x];

        int currentInputLength = parentPerceptron1.getInputLength();
        float mutationRate = parentPerceptron1.getMutationRate();
        float learningRate = parentPerceptron1.getLearningRate();
        float[] weights1 = parentPerceptron1.getWeights();
        float[] weights2 = parentPerceptron2.getWeights();

        Perceptron childPerceptron = new Perceptron(currentInputLength,
                learningRate, mutationRate);

        float[] childWeights = new float[weights1.length];

        int indexZ = (y == 0) ? INPUT_AMOUNT : p1Layers[y - 1].length;

        for (int z = 0; z < indexZ; z++) {

          childWeights[z] = (Util.nextInt(3) > 0) ? weights1[z] : weights2[z];

        }

        childPerceptron.setWeights(childWeights);
        childPerceptron.mutate();

        childLayers[y][x] = childPerceptron;

      }

    }

    NeuralNetwork childNetwork = new NeuralNetwork(INPUT_AMOUNT,
            HIDDEN_LAYER_AMOUNT,
            OUTPUT_AMOUNT, LEARNING_RATE, MUTATION_RATE, true);

    childNetwork.setLayers(childLayers);

    child.setNetwork(childNetwork);

    return child;

  }

  @Override
  public Bird clone() {

    Bird bird = new Bird();

    bird.fitness = fitness;

    bird.bounds = bounds;

    bird.network = network;

    bird.color = color;

    return bird;

  }

  /**
   * Calculate the fitness
   *
   * @param bottomColumn
   * @param gapHeight
   */
  public void calcFitness(Rectangle bottomColumn, int gapHeight) {

    int dis = getDistanceTravelled() * 2; // travelled distance is important
    int gap = getVerticalGapDis(bottomColumn, gapHeight, true) * 2;

    fitness = (dis - gap);

  }

  /**
   * @return the fitness
   */
  public float getFitness() {

    return fitness;
  }

  /**
   * @return the network
   */
  public NeuralNetwork getNetwork() {

    return network;
  }

  /**
   * @param network the network to set
   */
  public void setNetwork(NeuralNetwork network) {

    this.network = network;
  }

  /**
   * Horizontal distance travelled.
   *
   * @return
   */
  public int getDistanceTravelled() {

    return distance;
  }

  /**
   * Get the vertical distance to the gap of the column.
   * Closer to 0 is good.
   *
   * @param bottomColumn
   * @param gapHeight
   * @return
   */
  public int getVerticalGapDis(Rectangle bottomColumn, int gapHeight,
          boolean isAbs) {

    int birdY = bounds.y + bounds.height / 2;
    int gapY = bottomColumn.y - gapHeight / 2;

    int result = (birdY - gapY);

    if (isAbs && result < 0) {
      result = -result;
    }

    return result;

  }

  /**
   * @return the yMotion
   */
  public int getMotionY() {

    return motionY;
  }

  /**
   * @param yMotion the yMotion to set
   */
  public void setMotionY(int yMotion) {

    this.motionY = yMotion;
  }

  /**
   * @return the color
   */
  public Color getColor() {

    return color;
  }

  /**
   * @param color the color to set
   */
  public void setColor(Color color) {

    this.color = color;
  }

  /**
   * @return the score
   */
  public int getScore() {
    return score;
  }

  /**
   * @param score the score to set
   */
  public void setScore(int score) {
    this.score = score;
  }

}
