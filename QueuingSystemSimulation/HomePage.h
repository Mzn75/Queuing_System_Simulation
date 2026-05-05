#pragma once
#include "Queue.h"
#include <cstdlib>

extern ::Queue q;

namespace QueuingSystemSimulation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class HomePage : public System::Windows::Forms::Form
	{
	public:
		HomePage(void)
		{
			InitializeComponent();
		}

	protected:
	~HomePage()
		{
			if (components)
			{
				delete components;
			}
		}

	//UI Components
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ enqueueBtn;
	private: System::Windows::Forms::Button^ dequeueBtn;
	private: System::Windows::Forms::Button^ startBtn;
	private: System::Windows::Forms::TextBox^ outputTxtBox;
	private: System::Windows::Forms::TextBox^ queueLengthTxtBox;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Timer^ simTimer;
	private: System::Windows::Forms::TextBox^ timeTxtBox;
	private: System::Windows::Forms::ComboBox^ numOfServersBox;
	private: System::Windows::Forms::CheckBox^ autoArrivalBox;
	private: System::Windows::Forms::ProgressBar^ progressBar;
	private: System::Windows::Forms::Button^ resetBtn;
	private: System::Windows::Forms::ComboBox^ simTimeBox;

	// Simulation Variables
	private: int currentTime;
	private: int simulationTime;
	private: int* arrivalTimes;
	private: int* serviceTimes;
	private: int* serverBusy;
	private: int numServers;
	private: int totalArrived;
	private: int totalServed;
	private: int totalWaitTime;
	private: int arrivalRate;
	private: int nextId;

	protected:

	private:



#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(HomePage::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->enqueueBtn = (gcnew System::Windows::Forms::Button());
			this->dequeueBtn = (gcnew System::Windows::Forms::Button());
			this->startBtn = (gcnew System::Windows::Forms::Button());
			this->outputTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->queueLengthTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->simTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->timeTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->numOfServersBox = (gcnew System::Windows::Forms::ComboBox());
			this->autoArrivalBox = (gcnew System::Windows::Forms::CheckBox());
			this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->resetBtn = (gcnew System::Windows::Forms::Button());
			this->simTimeBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(132, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(272, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Queuing System Simulation";
			// 
			// enqueueBtn
			// 
			this->enqueueBtn->BackColor = System::Drawing::Color::White;
			this->enqueueBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->enqueueBtn->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->enqueueBtn->FlatAppearance->BorderSize = 3;
			this->enqueueBtn->FlatAppearance->CheckedBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(175)), static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->enqueueBtn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(175)), static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->enqueueBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->enqueueBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->enqueueBtn->Location = System::Drawing::Point(49, 91);
			this->enqueueBtn->Name = L"enqueueBtn";
			this->enqueueBtn->Size = System::Drawing::Size(95, 43);
			this->enqueueBtn->TabIndex = 1;
			this->enqueueBtn->Text = L"Enqueue";
			this->enqueueBtn->UseVisualStyleBackColor = false;
			this->enqueueBtn->Click += gcnew System::EventHandler(this, &HomePage::enqueueBtn_Click);
			// 
			// dequeueBtn
			// 
			this->dequeueBtn->BackColor = System::Drawing::Color::White;
			this->dequeueBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->dequeueBtn->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->dequeueBtn->FlatAppearance->BorderSize = 3;
			this->dequeueBtn->FlatAppearance->CheckedBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(175)), static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->dequeueBtn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(175)), static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->dequeueBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dequeueBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dequeueBtn->Location = System::Drawing::Point(177, 91);
			this->dequeueBtn->Name = L"dequeueBtn";
			this->dequeueBtn->Size = System::Drawing::Size(95, 43);
			this->dequeueBtn->TabIndex = 2;
			this->dequeueBtn->Text = L"Dequeue";
			this->dequeueBtn->UseVisualStyleBackColor = false;
			this->dequeueBtn->Click += gcnew System::EventHandler(this, &HomePage::dequeueBtn_Click);
			// 
			// startBtn
			// 
			this->startBtn->BackColor = System::Drawing::Color::White;
			this->startBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->startBtn->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->startBtn->FlatAppearance->BorderSize = 3;
			this->startBtn->FlatAppearance->CheckedBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(175)), static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->startBtn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(175)), static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->startBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->startBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->startBtn->Location = System::Drawing::Point(305, 91);
			this->startBtn->Name = L"startBtn";
			this->startBtn->Size = System::Drawing::Size(95, 43);
			this->startBtn->TabIndex = 3;
			this->startBtn->Text = L"Start";
			this->startBtn->UseVisualStyleBackColor = false;
			this->startBtn->Click += gcnew System::EventHandler(this, &HomePage::startBtn_Click);
			// 
			// outputTxtBox
			// 
			this->outputTxtBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->outputTxtBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->outputTxtBox->Cursor = System::Windows::Forms::Cursors::No;
			this->outputTxtBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputTxtBox->ForeColor = System::Drawing::Color::White;
			this->outputTxtBox->Location = System::Drawing::Point(12, 225);
			this->outputTxtBox->Name = L"outputTxtBox";
			this->outputTxtBox->ReadOnly = true;
			this->outputTxtBox->Size = System::Drawing::Size(511, 28);
			this->outputTxtBox->TabIndex = 5;
			this->outputTxtBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// queueLengthTxtBox
			// 
			this->queueLengthTxtBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->queueLengthTxtBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->queueLengthTxtBox->Cursor = System::Windows::Forms::Cursors::No;
			this->queueLengthTxtBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->queueLengthTxtBox->ForeColor = System::Drawing::Color::White;
			this->queueLengthTxtBox->Location = System::Drawing::Point(12, 259);
			this->queueLengthTxtBox->Name = L"queueLengthTxtBox";
			this->queueLengthTxtBox->ReadOnly = true;
			this->queueLengthTxtBox->Size = System::Drawing::Size(511, 28);
			this->queueLengthTxtBox->TabIndex = 6;
			this->queueLengthTxtBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// simTimer
			// 
			this->simTimer->Interval = 1000;
			this->simTimer->Tick += gcnew System::EventHandler(this, &HomePage::simTimer_Tick);
			// 
			// timeTxtBox
			// 
			this->timeTxtBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->timeTxtBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->timeTxtBox->Cursor = System::Windows::Forms::Cursors::No;
			this->timeTxtBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timeTxtBox->ForeColor = System::Drawing::Color::White;
			this->timeTxtBox->Location = System::Drawing::Point(12, 293);
			this->timeTxtBox->Name = L"timeTxtBox";
			this->timeTxtBox->ReadOnly = true;
			this->timeTxtBox->Size = System::Drawing::Size(511, 28);
			this->timeTxtBox->TabIndex = 7;
			this->timeTxtBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// numOfServersBox
			// 
			this->numOfServersBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->numOfServersBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->numOfServersBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->numOfServersBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numOfServersBox->FormattingEnabled = true;
			this->numOfServersBox->Location = System::Drawing::Point(177, 170);
			this->numOfServersBox->Name = L"numOfServersBox";
			this->numOfServersBox->Size = System::Drawing::Size(153, 25);
			this->numOfServersBox->Sorted = true;
			this->numOfServersBox->TabIndex = 8;
			this->numOfServersBox->SelectedIndexChanged += gcnew System::EventHandler(this, &HomePage::numOfServersBox_SelectedIndexChanged);
			// 
			// autoArrivalBox
			// 
			this->autoArrivalBox->AutoSize = true;
			this->autoArrivalBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->autoArrivalBox->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->autoArrivalBox->FlatAppearance->BorderSize = 2;
			this->autoArrivalBox->FlatAppearance->CheckedBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(175)), static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->autoArrivalBox->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(175)), static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->autoArrivalBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->autoArrivalBox->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->autoArrivalBox->ForeColor = System::Drawing::Color::White;
			this->autoArrivalBox->Location = System::Drawing::Point(49, 169);
			this->autoArrivalBox->Name = L"autoArrivalBox";
			this->autoArrivalBox->Size = System::Drawing::Size(117, 24);
			this->autoArrivalBox->TabIndex = 10;
			this->autoArrivalBox->Text = L"Auto Arrival";
			this->autoArrivalBox->UseVisualStyleBackColor = true;
			// 
			// progressBar
			// 
			this->progressBar->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(97)), static_cast<System::Int32>(static_cast<System::Byte>(175)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->progressBar->Location = System::Drawing::Point(25, 342);
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(485, 19);
			this->progressBar->TabIndex = 11;
			// 
			// resetBtn
			// 
			this->resetBtn->BackColor = System::Drawing::Color::White;
			this->resetBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->resetBtn->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->resetBtn->FlatAppearance->BorderSize = 3;
			this->resetBtn->FlatAppearance->CheckedBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(175)), static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->resetBtn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::IndianRed;
			this->resetBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->resetBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resetBtn->Location = System::Drawing::Point(433, 91);
			this->resetBtn->Name = L"resetBtn";
			this->resetBtn->Size = System::Drawing::Size(53, 43);
			this->resetBtn->TabIndex = 12;
			this->resetBtn->Text = L"Reset";
			this->resetBtn->UseVisualStyleBackColor = false;
			this->resetBtn->Click += gcnew System::EventHandler(this, &HomePage::resetBtn_Click);
			// 
			// simTimeBox
			// 
			this->simTimeBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->simTimeBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->simTimeBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->simTimeBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->simTimeBox->FormattingEnabled = true;
			this->simTimeBox->Location = System::Drawing::Point(351, 169);
			this->simTimeBox->Name = L"simTimeBox";
			this->simTimeBox->Size = System::Drawing::Size(135, 25);
			this->simTimeBox->TabIndex = 13;
			// 
			// HomePage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->ClientSize = System::Drawing::Size(535, 373);
			this->Controls->Add(this->simTimeBox);
			this->Controls->Add(this->resetBtn);
			this->Controls->Add(this->progressBar);
			this->Controls->Add(this->autoArrivalBox);
			this->Controls->Add(this->numOfServersBox);
			this->Controls->Add(this->timeTxtBox);
			this->Controls->Add(this->queueLengthTxtBox);
			this->Controls->Add(this->outputTxtBox);
			this->Controls->Add(this->startBtn);
			this->Controls->Add(this->dequeueBtn);
			this->Controls->Add(this->enqueueBtn);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"HomePage";
			this->Text = L"HomePage";
			this->Load += gcnew System::EventHandler(this, &HomePage::HomePage_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	//HomePage Load Event - Initialize Variables
	private: System::Void HomePage_Load(System::Object^ sender, System::EventArgs^ e) {
		outputTxtBox->Visible = false;
		queueLengthTxtBox->Visible = false;
		timeTxtBox->Visible = false;
		autoArrivalBox->Checked = true;

		progressBar->Minimum = 0;	
		progressBar->Value = 0;

		arrivalTimes = new int[100];
		serviceTimes = new int[100];

		numServers = 1;
		serverBusy = new int[3];
		for (int i = 0; i < 3; i++) serverBusy[i] = 0;

		nextId = 1;
		totalArrived = 0;
		totalServed = 0;
		totalWaitTime = 0;
		arrivalRate = 3;
		currentTime = 0;
		simulationTime = 30;

		numOfServersBox->Items->Add("1 Server");
		numOfServersBox->Items->Add("2 Servers");
		numOfServersBox->Items->Add("3 Servers");
		numOfServersBox->SelectedIndex = 0;

		simTimeBox->Items->Add("30 Seconds");
		simTimeBox->Items->Add("60 Seconds");
		simTimeBox->Items->Add("90 Seconds");
		simTimeBox->Items->Add("120 Seconds");
		simTimeBox->SelectedIndex = 0;
	}

	// Enqueue Button Click Event
	private: System::Void enqueueBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (autoArrivalBox->Checked) {
			outputTxtBox->Visible = true;
			outputTxtBox->Text = "Disable Auto Arrival First !";
			return;
		}

		if (q.getSize() >= 100) {
			outputTxtBox->Visible = true;
			outputTxtBox->Text = "Queue is Full ! Cannot Enqueue More Customers";
			return;
		}

		int id = nextId++;
		arrivalTimes[id] = currentTime;
		serviceTimes[id] = rand() % 4 + 1;
		q.enqueue(id);
		totalArrived++;
		outputTxtBox->Visible = true;
		queueLengthTxtBox->Visible = true;
		outputTxtBox->Text = "Enqueued, Customer ID: " + id.ToString();
		queueLengthTxtBox->Text = "Queue length: " + q.getSize().ToString();
	}

	// Dequeue Button Click Event
	private: System::Void dequeueBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		outputTxtBox->Visible = true;
		queueLengthTxtBox->Visible = true;
		if (!q.isEmpty()) {
			int id = q.peek();
			q.dequeue();
			outputTxtBox->Text = "Dequeued, Customer ID: " + id.ToString();
		}
		else {
			outputTxtBox->Text = "Queue is Empty";
		}
		queueLengthTxtBox->Text = "Queue length: " + q.getSize().ToString();
	}	

	// Start Button Click Event - Start Simulation
	private: System::Void startBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (q.isEmpty() && !autoArrivalBox->Checked) {
			outputTxtBox->Visible = true;
			outputTxtBox->Text = "No customers in the Queue ! Enqueue First !";
			return;
		}

		nextId = 1;
		currentTime = 0;
		totalArrived = 0;
		totalServed = 0;
		totalWaitTime = 0;
		simulationTime = (simTimeBox->SelectedIndex + 1) * 30;
		progressBar->Maximum = simulationTime;

		numServers = numOfServersBox->SelectedIndex + 1;
		for (int i = 0; i < 3; i++) serverBusy[i] = 0;
		outputTxtBox->Visible = true;
		queueLengthTxtBox->Visible = true;
		timeTxtBox->Visible = true;
		startBtn->Enabled = false;
		enqueueBtn->Enabled = false;
		dequeueBtn->Enabled = false;
		resetBtn->Enabled = false;
		simTimer->Start();
	}

	// Simulation Timer Tick Event - Main Simulation Logic
	private: System::Void simTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (currentTime >= simulationTime) {
			simTimer->Stop();
			startBtn->Enabled = true;
			enqueueBtn->Enabled = true;
			dequeueBtn->Enabled = true;
			resetBtn->Enabled = true;

			double avgWait = 0;
			if (totalServed > 0)
				avgWait = (double)totalWaitTime / totalServed;

			outputTxtBox->Text = "Done ! Served: " + totalServed.ToString() + " | Arrived: " + totalArrived.ToString();
			queueLengthTxtBox->Text = "Avg wait: " + ((int)avgWait).ToString() + " Seconds";
			timeTxtBox->Text = "Simulation Completed !";
			return;
		}

		for (int i = 0; i < numServers; i++) {
			if (serverBusy[i] > 0) serverBusy[i]--;
		}

		if (autoArrivalBox->Checked) {
			if (rand() % arrivalRate == 0) {
				int id = nextId++;
				arrivalTimes[id] = currentTime;
				serviceTimes[id] = rand() % 4 + 1;
				q.enqueue(id);
				totalArrived++;
			}
		}

		String^ servedText = "";
		for (int i = 0; i < numServers; i++) {
			if (serverBusy[i] == 0 && !q.isEmpty()) {
				int id = q.peek();
				q.dequeue();
				int waitTime = currentTime - arrivalTimes[id];
				totalWaitTime += waitTime;
				totalServed++;
				serverBusy[i] = serviceTimes[id];
				servedText += "Server " + (i + 1).ToString() + ": Customer ID: " + id.ToString() + " (Waited: " + waitTime.ToString() + " Seconds)";
			}
		}

		if (servedText != "")
			outputTxtBox->Text = servedText;
		else
			outputTxtBox->Text = "No Customers Being Served";

		timeTxtBox->Text = "Time: " + currentTime.ToString() + " Seconds";
		queueLengthTxtBox->Text = "Queue: " + q.getSize().ToString() + " | Served: " + totalServed.ToString()+ " | Arrived: " + totalArrived.ToString();

		if (q.isEmpty() && !autoArrivalBox->Checked) {
			simTimer->Stop();
			startBtn->Enabled = true;
			enqueueBtn->Enabled = true;
			dequeueBtn->Enabled = true;
			resetBtn->Enabled = true;

			double avgWait = 0;
			if (totalServed > 0)
				avgWait = (double)totalWaitTime / totalServed;

			outputTxtBox->Text = "Done ! Served: " + totalServed.ToString() + " | Arrived: " + totalArrived.ToString();
			queueLengthTxtBox->Text = "Avg wait: " + ((int)avgWait).ToString() + " Seconds";
			timeTxtBox->Text = "Simulation Completed !";
			progressBar->Value = progressBar->Maximum;
			return;
		}

		currentTime++;
		progressBar->Value = currentTime;
	}

	private: System::Void numOfServersBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void resetBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		//Stop Timer
		simTimer->Stop();

		//Reset all values
		currentTime = 0;
		simulationTime = 30;
		totalArrived = 0;
		totalServed = 0;
		totalWaitTime = 0;
		nextId = 1;
		for (int i = 0; i < 3; i++) serverBusy[i] = 0;

		//Clear the queue
		while (!q.isEmpty()) q.dequeue();

		//Reset UI
		outputTxtBox->Text = "";
		queueLengthTxtBox->Text = "";
		timeTxtBox->Text = "";
		progressBar->Value = 0;

		outputTxtBox->Visible = false;
		queueLengthTxtBox->Visible = false;
		timeTxtBox->Visible = false;

		startBtn->Enabled = true;
		enqueueBtn->Enabled = true;
		dequeueBtn->Enabled = true;

		numOfServersBox->SelectedIndex = 0;

		simTimeBox->SelectedIndex = 0;
		progressBar->Maximum = 30;
	}
};

};