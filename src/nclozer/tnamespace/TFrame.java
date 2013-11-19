package nclozer.tnamespace;

abstract public class TFrame
{
    /* Static initializer block */
    static {
        System.loadLibrary("nLib");
    }
    
    abstract public void init();

}
