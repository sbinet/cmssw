/* Generated by Together */

import cern.dip.*;

/**
 * This class publishes for a short time, unregister, reregisters and republishes.
 * We are trying to crash the implementation by having this going on in many threads.
 */
public class ShortLivedPublisher extends Thread implements DipPublicationErrorHandler {
    DipFactory factory;
    public String pubName;
    static int disconnectCount = 0;

    public void handleException(DipPublication p, DipException e) {
        System.out.println(p.getTopicName());
        e.printStackTrace();
    }

    public ShortLivedPublisher(String publisherName, DipFactory dipFactory) {
        pubName = publisherName;
        factory = dipFactory;
    }

    public void run() {
        while (true) {
            int sleep_ms = (int)((java.lang.Math.random() * (float)10000) + 100); // upto 10sec
            try {
                int count = (int)((java.lang.Math.random() * (float)100) + 10);
                int sendSleep_ms = (int)((java.lang.Math.random() * (float)1000)); // upto 1sec
                DipPublication pub = factory.createDipPublication(pubName, this);
                while (count != 0) {
                    DipTimestamp ts = new DipTimestamp();
                    pub.send(count, ts);
                    Thread.sleep(sendSleep_ms);
                    count--;
                }
                factory.destroyDipPublication(pub);
                disconnectCount++;
                System.out.println(disconnectCount + " disconnections");
            } catch (Throwable t) {
                System.out.println("Java:- " + t.getMessage());
            }
			try{
             Thread.sleep(sleep_ms);
            } catch (Throwable t) {
                System.out.println("Java:- " + t.getMessage());
            }
        }
    }

    public static void main(String[] args) {
        DipFactory df = Dip.create("ShortLivedTestWindows");
        ShortLivedPublisher[] pubs = new ShortLivedPublisher[100];
        for (int i = 0; i < pubs.length; i++) {
            pubs[i] = new ShortLivedPublisher("test.shortLived" + i, df);
            pubs[i].start();
        }
		ShortLivedPublisher badPub = new ShortLivedPublisher(pubs[0].pubName, df);
        badPub.start();

        while (true) {
            try {
                Thread.sleep(1000);
            } catch (Throwable t) {
                t.printStackTrace();
            }
        }
    }
}
