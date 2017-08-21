import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.InputStream;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Arrays;

import javax.imageio.ImageIO;

public class Client {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Client ob = new Client();
		ob.ConnectToServer();
	}

	private void ConnectToServer() {
		// TODO Auto-generated method stub
		try {
			Registry reg1=LocateRegistry.getRegistry("localhost",1096);
			String registryURL1="rmi://localhost"+1096+"server";
			
			Registry reg2=LocateRegistry.getRegistry("localhost",1097);
			String registryURL2="rmi://localhost"+1097+"server";
			
			Registry reg3=LocateRegistry.getRegistry("localhost",1098);
			String registryURL3="rmi://localhost"+1098+"server";
			
			Registry reg4=LocateRegistry.getRegistry("localhost",1099);
			String registryURL4="rmi://localhost"+1099+"server";
			
			Sample PC1= (Sample)reg1.lookup(registryURL1);
			System.out.println("Connected To server 1. Now U go");
			
			Sample PC2= (Sample)reg2.lookup(registryURL2);
			System.out.println("Connected To server 2. Now U go");
			
			Sample PC3= (Sample)reg3.lookup(registryURL3);
			System.out.println("Connected To server 3. Now U go");
			
			Sample PC4= (Sample)reg4.lookup(registryURL4);
			System.out.println("Connected To server 4. Now U go");
			
			
    //Main Code Start
			
			byte[] imageInByte;
			BufferedImage originalImage=ImageIO.read(new File("C:/Users/Jaggesher/Desktop/input.jpg"));
			ByteArrayOutputStream baos= new ByteArrayOutputStream();
			ImageIO.write(originalImage, "jpg", baos);
			baos.flush();
			imageInByte=baos.toByteArray();
			baos.close();
			
			int len=imageInByte.length/4;
			byte[] FirstPart=  Arrays.copyOfRange(imageInByte,0,len);
			byte[] SecPart= Arrays.copyOfRange(imageInByte, len, (len*2));
			byte[] ThirdPart= Arrays.copyOfRange(imageInByte, (len*2), (len*3));
			byte[] FourthPart= Arrays.copyOfRange(imageInByte, (len*3), imageInByte.length);
			
//			System.out.println(FirstPart.length+SecPart.length+ThirdPart.length+FourthPart.length);
//			System.out.println(imageInByte.length);
			
			byte[] RecFirst=PC1.ProcessIT(FirstPart);
			byte[] RecSec=PC2.ProcessIT(SecPart);
			byte[] RecThird=PC3.ProcessIT(ThirdPart);
			byte[] RecFourth=PC4.ProcessIT(FourthPart);
			
			
			byte[] RecByteImage=new byte[RecFirst.length+RecSec.length+RecThird.length+RecFourth.length];
			System.arraycopy(RecFirst, 0, RecByteImage, 0, RecFirst.length);
			System.arraycopy(RecSec, 0, RecByteImage, RecFirst.length, RecSec.length);
			System.arraycopy(RecThird, 0, RecByteImage, (RecFirst.length+RecSec.length), RecThird.length);
			System.arraycopy(RecFourth, 0, RecByteImage, (RecFirst.length+RecSec.length+RecThird.length), RecFourth.length);
			
			
			InputStream in = new ByteArrayInputStream(RecByteImage);
			BufferedImage buffImage=ImageIO.read(in);
			
			ImageIO.write(buffImage, "jpg", new File("C:/Users/Jaggesher/Desktop/output.jpg"));
			System.out.println("image Saved.");
			
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println(e);
		}
	}

}
