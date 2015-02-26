//package monitor;

import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.Arrays;
import java.util.Date;

public class Reading {
	/**
	 * The size required to store a reading.
	 */
	static final int SIZE = Long.SIZE * 2 
			+ Integer.SIZE + Float.SIZE;
	/**
	 * ByteBuffer is a handy type for storing binary data.
	 */
	final ByteBuffer buf;
	
	final int length = SIZE + Integer.SIZE; 
	
	/**
	 * Constructs a Reading from the given values. 
	 */
	public Reading(long id, long time, int pulse, float temp) {
		buf = ByteBuffer.allocate(length);		
		buf.putLong(id);
		buf.putLong(time);
		buf.putInt(pulse);
		buf.putFloat(temp);
		buf.putFloat(length);		
	}
	
	/**
	 * Constructs a Reading from the given stream. 
	 */	
	public Reading(DataInputStream sin) throws IOException {
		byte[] a = new byte[length];
		sin.readFully(a);
		buf = ByteBuffer.wrap(a);
	}
	
	/**
	 * @return the underlying data array.
	 */
	byte[] data() {
		return buf.array();
	}
	
	/**
	 * Reading data rendered as a string. 
	 */
	@Override
	public String toString() {
		return "ID:" + buf.getLong()
			+ ", time:" + new Date(buf.getLong())
			+ ", pulse:" + buf.getInt()
			+ ", temp:" + buf.getFloat() 
			+ ", length:" + buf.getFloat();
	}
	
	/**
	 * A quick unit test for the class. 
	 */
	/*public static void main(String[] args) throws IOException {
		Reading p1 = new Reading(12345l, 
				System.currentTimeMillis(),
				60,	37.5f);
		
		DataInputStream din = new DataInputStream( 
				new ByteArrayInputStream(p1.data()));
		
		Reading p2 = new Reading(din);
		//System.out.println(p2);
		assert Arrays.equals(p1.data(), p2.data());
	}*/
}
