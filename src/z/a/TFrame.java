package z.a;

abstract public class TFrame
{
    /* Static initializer block */
    static {
        System.loadLibrary("TApp");
    }
    
    abstract public void tInit();
}
