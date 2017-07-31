import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.InputStream;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

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
			Registry reg=LocateRegistry.getRegistry("localhost",1098);
			String registryURL="rmi://localhost"+1098+"server";
			
			Sample sampOB= (Sample)reg.lookup(registryURL);
			System.out.println("Connected To server. Now U go");
			
			byte[] imageInByte;
			BufferedImage originalImage=ImageIO.read(new File("C:/Users/Jaggesher/Desktop/tst.jpg"));
			ByteArrayOutputStream baos= new ByteArrayOutputStream();
			ImageIO.write(originalImage, "jpg", baos);
			baos.flush();
			imageInByte=baos.toByteArray();
			baos.close();
			
			byte[] RecByteImage= sampOB.ProcessIT(imageInByte);
			
			InputStream in = new ByteArrayInputStream(RecByteImage);
			BufferedImage buffImage=ImageIO.read(in);
			
			ImageIO.write(buffImage, "jpg", new File("C:/Users/Jaggesher/Desktop/tst2.jpg"));
			System.out.println("image Saved.");
			
			//sampOB.ProcessIT(image);
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println(e);
		}
	}

}
