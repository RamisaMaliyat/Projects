<?php

include("../config.php");

if( isset($_REQUEST['action']) ){


	switch( $_REQUEST['action'] ){



		case "SendMessage":
		//session_start();
		
			$query = $db->prepare("INSERT INTO chat SET user=?, message=?");

			$query->execute(['Someone', $_REQUEST['message']]);

			echo 1;
		break;
		
		
		
		case "getChat":


			$query = $db->prepare("SELECT * from chat");
			$query->execute();
            $rs = $query->fetchAll(PDO::FETCH_OBJ);
			
			

			$chat = '';
			foreach($rs as $p){

				$chat .=$p->user.'  says:  '.$p->message.'<hr />';

			}

			echo $chat;


		break;
		
		

	}
}


?>
