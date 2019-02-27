﻿using System;
using System.Net;
using System.Text;
using System.IO.Ports;
using System.Threading;
using System.IO;

/// <summary>
/// This code is the source desktop API of the 
/// MCI system. Here a localhost is created and
/// data from the browser is awaited. Upon Successfullly
/// getting the data from the browser, an ack. char. is
/// sent to the browser i.e "R".
/// </summary>


namespace comInterpt
{
	class MainClass
	{

		const string webPort = "3333";
		const string Prefix = "http://localhost:"+webPort+"/";

		static int[] old_coordinates = new int[8];
		const int oc_X = 0;
		const int oc_Y = 1;
		const int oc_Z = 2;
		const int oc_U = 3;
		const int oc_V = 4;
		const int oc_W = 5;
		const int oc_LP = 6;
		const int oc_RP = 7;
		/// <summary>
		/// This is the function which gets called when the data is recieved by the 
		/// desktop API
		/// </summary>
		/// <param name="x">The x coordinate.</param>
		/// <param name="y">The y coordinate.</param>
		/// <param name="z">The z coordinate.</param>
		/// <param name="u">The u coordinate.</param>
		/// <param name="v">The v coordinate.</param>
		/// <param name="w">The w coordinate.</param>

		public static void onRecieveCtrlData(int x, int y, int z, int u, int v, int w, int LP, int RP, int POS_S, int PRES_S){   // LP = left pressure, RP = right pressure
            string pos_s = resolveSensitivityParameter(POS_S);
            string pres_s = resolveSensitivityParameter(PRES_S);
            Console.WriteLine ("X = " + x.ToString ());
			Console.WriteLine ("Y = " + y.ToString ());
			Console.WriteLine ("Z = " + z.ToString ());
			Console.WriteLine ("U = " + u.ToString ());
			Console.WriteLine ("V = " + v.ToString ());
			Console.WriteLine ("W = " + w.ToString ());
			Console.WriteLine ("LP = " + LP.ToString ());
			Console.WriteLine ("RP = " + RP.ToString ());
            Console.WriteLine("POS_S = " + pos_s);
            Console.WriteLine("PRES_S = " + pres_s);
			Console.WriteLine("Sending data to machine...");
			comparedVal cv_x = compareValue(oc_X, x);
			comparedVal cv_y = compareValue(oc_Y, y);
			comparedVal cv_z = compareValue(oc_Z, z);
			comparedVal cv_u = compareValue(oc_U, u);
			comparedVal cv_v = compareValue(oc_V, v);
			comparedVal cv_w = compareValue(oc_W, w);
			comparedVal cv_lp = compareValue(oc_LP, LP);
			comparedVal cv_rp = compareValue(oc_RP, RP);
			sendDataToComport(cv_x, _serialport, "X", "x");
            sendDataToComport(cv_y, _serialport, "Y", "y");
            sendDataToComport(cv_z, _serialport, "Z", "z");
            sendDataToComport(cv_u, _serialport, "U", "u");
            sendDataToComport(cv_v, _serialport, "V", "v");
            sendDataToComport(cv_w, _serialport, "W", "w");
			sendDataToComport(cv_lp, _p_serialport, "Q", "q");
			sendDataToComport(cv_rp, _p_serialport, "P", "p");
            int charSendDelayMS = 1;
            try
            {
                _serialport.Write(pos_s);
                Thread.Sleep(charSendDelayMS);
                _p_serialport.Write(pres_s);
                Thread.Sleep(charSendDelayMS);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Could not send data to comport. \nError : " + ex.Message);
            }
        }


        public static string resolveSensitivityParameter(int param){
            // Convert the received sensitivity signal to a meaningfull response for the
            // concerned machine
            return param == 1 ? "G" : param == 2 ? "J" : param == 3 ? "K" : param == 4 ? "M" : param == 5 ? "I" : "";
        }
		struct comparedVal{
			public bool positive;
			public int difference;
		}

		static comparedVal compareValue(int old_val_index, int new_val, string refer = "n"){
			comparedVal cv = new comparedVal();
			//Console.WriteLine(refer + " new_val = " + new_val + " | old_val = " + old_coordinates);
			cv.difference = new_val - old_coordinates[old_val_index];
			cv.positive = true;
			if (cv.difference < 0){
				cv.positive = false;
			}
			old_coordinates[old_val_index] = new_val;
			return cv;
		}

		static void sendDataToComport(comparedVal cv, SerialPort serialport, string ch_inc, string ch_dec)
		{
            int charSendDelayMS = 1;
			try
			{
				string ch_toSend = ch_inc;
				if (!cv.positive)
				{
					ch_toSend = ch_dec;
				}
				Console.WriteLine("Difference ("+ch_inc+")= " + cv.difference.ToString());
				for (int c = 0; c < Math.Abs(cv.difference); c++)
                {
					serialport.Write(ch_toSend);
                    Thread.Sleep(charSendDelayMS);
                }
			}catch(Exception ex){
				Console.WriteLine("Could not send data to comport. \nError : " + ex.Message);
			}

		}




		const int comport_baudrate = 230400;
		const Parity comport_parity = Parity.None;
		const int comport_databits = 8;
		const StopBits comport_stopbit = StopBits.One;
		const Handshake comport_handshake = Handshake.None;

		const string comport_ack = "";   // The ack to be sent when the connection is made.

		static SerialPort _serialport = null;
		static SerialPort _p_serialport = null;
		static HttpListener Listener = null;
		static int RequestNumber = 0;
		static readonly DateTime StartupDate = DateTime.UtcNow;


		public static void Main(string[] args)
		{

			connectComPort();

			if (!HttpListener.IsSupported)
			{
				Console.WriteLine("HttpListener is not supported on this platform.");
				return;
			}




			using (Listener = new HttpListener())
			{

				Listener.Prefixes.Add(Prefix);
				Listener.Start();
				// Begin waiting for requests.
				Listener.BeginGetContext(GetContextCallback, null);
				Console.WriteLine("Listening to http://localhost:" + webPort + "/");
				Console.WriteLine("Close the application to end the session.");
				Console.WriteLine ("Listening Now : ");
				for (;;) {};
			}
		}

		static void GetContextCallback(IAsyncResult ar)
		{
			try{
				int req = ++RequestNumber;

				// Get the context
				var context = Listener.EndGetContext(ar);

				// listen for the next request
				Listener.BeginGetContext(GetContextCallback, null);

				// get the request
				var NowTime = DateTime.UtcNow;

				Console.WriteLine("{0}: {1}", NowTime.ToString("R"), context.Request.RawUrl);
					
				var request = context.Request;
				string text;
				using (var reader = new StreamReader(request.InputStream,request.ContentEncoding))
				{
					text = reader.ReadToEnd();
					Console.WriteLine(text);
					if(text.Contains(",")){
						var tarr = text.Split (",".ToCharArray());
						if(tarr.Length == 8){
							onRecieveCtrlData(
								
								int.Parse(tarr[0]),
								int.Parse(tarr[1]),
								int.Parse(tarr[2]),
								int.Parse(tarr[3]),
								int.Parse(tarr[4]),
								int.Parse(tarr[5]),
								int.Parse(tarr[6]),
								int.Parse(tarr[7]),
                                int.Parse(tarr[8]),
                                int.Parse(tarr[9])
							);
						}
					}
				}

				var responseString = string.Format("R");
				byte[] buffer = Encoding.UTF8.GetBytes(responseString);
				var response = context.Response;
				response.ContentType = "text/html";
				response.ContentLength64 = buffer.Length;
				response.StatusCode = 200;
				response.Headers.Remove("Access-Control-Allow-Origin");
				response.AddHeader("Access-Control-Allow-Origin", "*");
				response.OutputStream.Write(buffer, 0, buffer.Length);
				response.OutputStream.Close(); 
			}catch(Exception ex){
				Console.WriteLine (ex.Message);
			}
		}



		static string[] getComport(){
			string d_comport = "COM2";
			Console.Write("Enter the POSITION comport connected to the machine (default COM2) - press enter to continue - : ");
			string input = Console.ReadLine().Trim();
			string i1 = input == "" ? d_comport : input;
			Console.Write("Enter the PRESSURE comport connected to the machine (default COM1) - press enter to continue - : ");
			input = Console.ReadLine().Trim();
			d_comport = "COM1";
			string i2 = input == "" ? d_comport : input;
			return new string[] { i1, i2 };
		}

		static void connectComPort(){
			string[] comport = getComport();
			_serialport = new SerialPort(comport[0], comport_baudrate, comport_parity, comport_databits, comport_stopbit);
			_serialport.Handshake = comport_handshake;

			_p_serialport = new SerialPort(comport[1], comport_baudrate, comport_parity, comport_databits, comport_stopbit);
			_p_serialport.Handshake = comport_handshake;

			try{
				
				_serialport.Open();
				if(_serialport.IsOpen){
					_serialport.Write(comport_ack); 	
				}else{
					Console.WriteLine(comport[0] + " could not be opened check connection");
					Console.ReadLine();
					return;
				}

				_p_serialport.Open();
				if(_p_serialport.IsOpen){
					_p_serialport.Write(comport_ack); 	
				}else{
					Console.WriteLine(comport[1] + " could not be opened check connection");
					Console.ReadLine();
					return;
				}

			}catch (IOException ex)
			{
				Console.WriteLine("ComPorts not working! \nError : " + ex.Message + "\nCheck if you HAVE connected the machine correctly to : \n" +
					  "ComPort : " + comport);

			}
			catch (Exception ex)
			{
				Console.WriteLine(ex.Message);
			}
	
		}





	}
}
