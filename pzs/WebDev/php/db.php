<?php 
    class Database {
        private $host = "127.0.0.1";
        private $database_name = "database_name";
        private $username = "root";
        private $password = "password";

        public $conn;

        public function getConnection(){
            $this->conn = null;
            try{
                $this->conn = new PDO("mysql:host=" . $this->host . ";dbname=" . $this->database_name, $this->username, $this->password);
                $this->conn->exec("set names utf8");
            }catch(PDOException $exception){
                echo "Database could not be connected: " . $exception->getMessage();
            }
            return $this->conn;
        }
    }  
?>



<?php
//create rest api php mysql
    class Member{

        private $conn;

        private $db_table = "Member";

        public $id;
        public $member_name;
        public $email_address;
        public $point;
        public $serviceable;
        public $joined_at;

        public function __construct($db){
            $this->conn = $db;
        }

        public function getMembers(){
            $sqlQuery = "SELECT id, member_name, email_address, point, serviceable, joined_at FROM " . $this->db_table . "";
            $stmt = $this->conn->prepare($sqlQuery);
            $stmt->execute();
            return $stmt;
        }

        public function createMember(){
            $sqlQuery = "INSERT INTO
                        ". $this->db_table ."
                    SET
                        member_name = :member_name, 
                        email_address = :email_address, 
                        point = :point, 
                        serviceable = :serviceable, 
                        joined_at = :joined_at";
        
            $stmt = $this->conn->prepare($sqlQuery);
        
            $this->member_name=htmlspecialchars(strip_tags($this->member_name));
            $this->email_address=htmlspecialchars(strip_tags($this->email_address));
            $this->point=htmlspecialchars(strip_tags($this->point));
            $this->serviceable=htmlspecialchars(strip_tags($this->serviceable));
            $this->joined_at=htmlspecialchars(strip_tags($this->joined_at));
        
            $stmt->bindParam(":member_name", $this->member_name);
            $stmt->bindParam(":email_address", $this->email_address);
            $stmt->bindParam(":point", $this->point);
            $stmt->bindParam(":serviceable", $this->serviceable);
            $stmt->bindParam(":joined_at", $this->joined_at);
        
            if($stmt->execute()){
               return true;
            }
            return false;
        }

        public function getSingleMember(){
            $sqlQuery = "SELECT
                        id, 
                        member_name, 
                        email_address, 
                        point, 
                        serviceable, 
                        joined_at
                      FROM
                        ". $this->db_table ."
                    WHERE 
                       id = ?
                    LIMIT 0,1";

            $stmt = $this->conn->prepare($sqlQuery);

            $stmt->bindParam(1, $this->id);

            $stmt->execute();

            $dataRow = $stmt->fetch(PDO::FETCH_ASSOC);
            
            $this->member_name = $dataRow['member_name'];
            $this->email_address = $dataRow['email_address'];
            $this->point = $dataRow['point'];
            $this->serviceable = $dataRow['serviceable'];
            $this->joined_at = $dataRow['joined_at'];
        }        

        public function updateMember(){
            $sqlQuery = "UPDATE
                        ". $this->db_table ."
                    SET
                        member_name = :member_name, 
                        email_address = :email_address, 
                        point = :point, 
                        serviceable = :serviceable, 
                        joined_at = :joined_at
                    WHERE 
                        id = :id";
        
            $stmt = $this->conn->prepare($sqlQuery);
        
            $this->member_name=htmlspecialchars(strip_tags($this->member_name));
            $this->email_address=htmlspecialchars(strip_tags($this->email_address));
            $this->point=htmlspecialchars(strip_tags($this->point));
            $this->serviceable=htmlspecialchars(strip_tags($this->serviceable));
            $this->joined_at=htmlspecialchars(strip_tags($this->joined_at));
            $this->id=htmlspecialchars(strip_tags($this->id));
        
            $stmt->bindParam(":member_name", $this->member_name);
            $stmt->bindParam(":email_address", $this->email_address);
            $stmt->bindParam(":point", $this->point);
            $stmt->bindParam(":serviceable", $this->serviceable);
            $stmt->bindParam(":joined_at", $this->joined_at);
            $stmt->bindParam(":id", $this->id);
        
            if($stmt->execute()){
               return true;
            }
            return false;
        }

        function deleteMember(){
            $sqlQuery = "DELETE FROM " . $this->db_table . " WHERE id = ?";
            $stmt = $this->conn->prepare($sqlQuery);
        
            $this->id=htmlspecialchars(strip_tags($this->id));
        
            $stmt->bindParam(1, $this->id);
        
            if($stmt->execute()){
                return true;
            }
            return false;
        }

    }
?>





<?php
//create rest api php mysql
    header("Access-Control-Allow-Origin: *");
    header("Content-Type: application/json; charset=UTF-8");
    
    include_once '../config/db_connection.php';
    include_once '../class/members.php';

    $db_connection = new Database();
    $db = $db_connection->getConnection();

    $member_rows = new Member($db);

    $stmt = $member_rows->getMembers();
    $member_rowCount = $stmt->rowCount();


    echo json_encode($member_rowCount);

    if($member_rowCount > 0){
        
        $memberArr = array();
        $memberArr["body"] = array();
        $memberArr["member_rowCount"] = $member_rowCount;

        while ($row = $stmt->fetch(PDO::FETCH_ASSOC)){
            extract($row);
            $e = array(
                "id" => $id,
                "member_name" => $member_name,
                "email_address" => $email_address,
                "point" => $point,
                "serviceable" => $serviceable,
                "joined_at" => $joined_at
            );

            array_push($memberArr["body"], $e);
        }
        echo json_encode($memberArr);
    }

    else{
        http_response_code(404);
        echo json_encode(
            array("message" => "No record found.")
        );
    }
?>
<!-- Method	Endpoint
GET	https://www.pakainfo.com/api/read.php -->






<?php
    header("Access-Control-Allow-Origin: *");
    header("Content-Type: application/json; charset=UTF-8");
    header("Access-Control-Allow-Methods: POST");
    header("Access-Control-Max-Age: 3600");
    header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");

    include_once '../config/db_connection.php';
    include_once '../class/members.php';

    $db_connection = new Database();
    $db = $db_connection->getConnection();

    $member_row = new Member($db);

    $member_row->id = isset($_GET['id']) ? $_GET['id'] : die();
  
    $member_row->getSingleMember();

    if($member_row->member_name != null){
        // make array
        $emp_arr = array(
            "id" =>  $member_row->id,
            "member_name" => $member_row->member_name,
            "email_address" => $member_row->email_address,
            "point" => $member_row->point,
            "serviceable" => $member_row->serviceable,
            "joined_at" => $member_row->joined_at
        );
      
        http_response_code(200);
        echo json_encode($emp_arr);
    }
      
    else{
        http_response_code(404);
        echo json_encode("Member not found.");
    }
?>
<!-- Method	Endpoint
GET	https://www.pakainfo.com/api/single_read.php/?id=2 -->




<?php
    header("Access-Control-Allow-Origin: *");
    header("Content-Type: application/json; charset=UTF-8");
    header("Access-Control-Allow-Methods: POST");
    header("Access-Control-Max-Age: 3600");
    header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");

    include_once '../config/db_connection.php';
    include_once '../class/members.php';

    $db_connection = new Database();
    $db = $db_connection->getConnection();

    $member_row = new Member($db);

    $data = json_decode(file_get_contents("php://input"));

    $member_row->member_name = $data->member_name;
    $member_row->email_address = $data->email_address;
    $member_row->point = $data->point;
    $member_row->serviceable = $data->serviceable;
    $member_row->joined_at = date('Y-m-d H:i:s');
    
    if($member_row->createMember()){
        echo 'Member joined_at successfully.';
    } else{
        echo 'Member could not be joined_at.';
    }
?>
<!-- Method	Endpoint
POST	https://www.pakainfo.com/api/create.php -->




<?php
    header("Access-Control-Allow-Origin: *");
    header("Content-Type: application/json; charset=UTF-8");
    header("Access-Control-Allow-Methods: POST");
    header("Access-Control-Max-Age: 3600");
    header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");
    
    include_once '../config/db_connection.php';
    include_once '../class/members.php';
    
    $db_connection = new Database();
    $db = $db_connection->getConnection();
    
    $member_row = new Member($db);
    
    $data = json_decode(file_get_contents("php://input"));
    
    $member_row->id = $data->id;
    
    // member values
    $member_row->member_name = $data->member_name;
    $member_row->email_address = $data->email_address;
    $member_row->point = $data->point;
    $member_row->serviceable = $data->serviceable;
    $member_row->joined_at = date('Y-m-d H:i:s');
    
    if($member_row->updateMember()){
        echo json_encode("Member data updated.");
    } else{
        echo json_encode("Data could not be updated");
    }
?>
<!-- Method	Endpoint
POST	https://www.pakainfo.com/api/update.php -->



<?php
    header("Access-Control-Allow-Origin: *");
    header("Content-Type: application/json; charset=UTF-8");
    header("Access-Control-Allow-Methods: POST");
    header("Access-Control-Max-Age: 3600");
    header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");
    
    include_once '../config/db_connection.php';
    include_once '../class/members.php';
    
    $db_connection = new Database();
    $db = $db_connection->getConnection();
    
    $member_row = new Member($db);
    
    $data = json_decode(file_get_contents("php://input"));
    
    $member_row->id = $data->id;
    
    if($member_row->deleteMember()){
        echo json_encode("Member deleted.");
    } else{
        echo json_encode("Data could not be deleted");
    }
?>
<!-- Method	Endpoint
DELETE	https://www.pakainfo.com/api/delete.php -->